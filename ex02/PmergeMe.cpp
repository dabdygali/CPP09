/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:46:00 by dabdygal          #+#    #+#             */
/*   Updated: 2024/09/19 14:33:15 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include <sys/time.h>
#include <cerrno>
#include <stdexcept>
#include <cstring>
#include <list>
#include <iterator>
#include <algorithm>

std::ostream	&operator<<(std::ostream &out, std::vector<int> &rhs)
{
	size_t	i = 0;
	while (i < rhs.size())
	{
		out << rhs[i];
		if (i + 1 != rhs.size())
			out << ' ';
		i++;
	}
	return out;
}

static void	binary_insert(std::vector<int> &chain, std::vector<int> &unit)
{
	size_t	i, count, step, pos;
	count = chain.size() / unit.size();
	pos = 0;
	while (count > 0)
	{
		i = pos;
		step = count / 2;
		i += step;
		if (chain[(i * unit.size()) + unit.size() - 1] < unit.back())
		{
			pos = ++i;
			count -= step + 1;
		}
		else
			count = step;
	}
	i = 0;
	std::vector<int>::iterator 	it = chain.begin();
	std::advance(it, pos * unit.size());
	chain.insert(it, unit.begin(), unit.end());
}

static void	ford_johnson_sort(std::vector<int> &vec, size_t unitSize = 1)
{
	size_t								unitQty = vec.size() / unitSize;
	if (unitQty < 2)
		return;
	std::vector<int>::difference_type	spareUnitSize = (unitQty % 2) * unitSize;
	std::vector<int>::iterator			iter = vec.end();
	std::advance(iter, -spareUnitSize);
	std::vector<int>					spareUnit(iter, vec.end());
	vec.erase(iter, vec.end());
	unitQty = vec.size() / unitSize;

	size_t	index1 = unitSize - 1;
	size_t	index2 = index1 + unitSize;
	size_t	indexIncrement = unitSize * 2;
	size_t	i;
	while (index2 < vec.size())
	{
		if (vec[index1] > vec[index2])
		{
			int					tmp;
			i = index1 - unitSize + 1;
			while (i <= index1)
			{
				tmp = vec[i];
				vec[i] = vec[i + unitSize];
				vec[i + unitSize] = tmp;
				i++;
			}
		}
		index1 += indexIncrement;
		index2 += indexIncrement;
	}
	if (2 * unitSize < vec.size())
		ford_johnson_sort(vec, 2 * unitSize);
	std::vector<int>	secondaryChain;
	std::vector<int>	mainChain;
	i = 0;
	while (i < unitSize)
	{
		mainChain.push_back(vec[i]);
		i++;
	}
	i = 0;
	size_t	j = 0;
	while (i < unitQty)
	{
		j = i * unitSize;
		while (j < (i + 1) * unitSize)
		{
			if (i % 2)
				mainChain.push_back(vec[j]);
			else
				secondaryChain.push_back(vec[j]);				
			j++;
		}
		i++;
	}
	vec.clear();
	size_t	jacobsthalNumbers[28] = {3, 5, 11, 21, 43, 85, 171, 341, 683, \
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, \
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, \
	178956971, 357913941};
	j = 0;
	while (jacobsthalNumbers[j] <= secondaryChain.size() && j < 28)
		j++;
	i = 0;
	size_t	posRight;
	size_t	posLeft;
	posLeft = 1;
	std::vector<int>	unitB;
	size_t	k;
	while (i <= j)
	{
		posRight = jacobsthalNumbers[i];
		if (i > 0)
			posLeft = jacobsthalNumbers[i - 1];
		while (posRight > posLeft)
		{
			if (posRight <= (secondaryChain.size() / unitSize))
			{
				unitB.clear();
				k = (posRight - 1) * unitSize;
				while (k < posRight * unitSize)
				{
					unitB.push_back(secondaryChain[k]);
					k++;
				}
				binary_insert(mainChain, unitB);
			}
			posRight--;
		}
		i++;
	}
	if (!spareUnit.empty())
	{
		binary_insert(mainChain, spareUnit);
	}
	vec = mainChain;
}

static void	binary_insert(std::list<int> &chain, std::list<int> &unit)
{
	size_t	i, count, step, pos;
	count = chain.size() / unit.size();
	pos = 0;
	std::list<int>::iterator	il;
	while (count > 0)
	{
		i = pos;
		step = count / 2;
		i += step;
		il = chain.begin();
		std::advance(il, (i * unit.size()) + unit.size() - 1);
		if (*il < unit.back())
		{
			pos = ++i;
			count -= step + 1;
		}
		else
			count = step;
	}
	i = 0;
	std::list<int>::iterator 	it = chain.begin();
	std::advance(it, pos * unit.size());
	chain.insert(it, unit.begin(), unit.end());
}

static void	ford_johnson_sort(std::list<int> &lst, size_t unitSize = 1)
{
	size_t								unitQty = lst.size() / unitSize;
	if (unitQty < 2)
		return;
	std::list<int>::difference_type	spareUnitSize = (unitQty % 2) * unitSize;
	std::list<int>::iterator			iter = lst.end();
	std::advance(iter, -spareUnitSize);
	std::list<int>					spareUnit(iter, lst.end());
	lst.erase(iter, lst.end());
	unitQty = lst.size() / unitSize;

	size_t	index1 = unitSize - 1;
	size_t	index2 = index1 + unitSize;
	size_t	indexIncrement = unitSize * 2;
	size_t	i;
	std::list<int>::iterator	iter1, iter2;
	iter1 = lst.begin();
	std::advance(iter1, index1);
	iter2 = lst.begin();
	std::advance(iter2, index2);
	std::list<int>::iterator	il = lst.begin();
	std::list<int>::iterator	il2 = lst.begin();
	while (index2 < lst.size())
	{
		if (*iter1 > *iter2)
		{
			int					tmp;
			i = index1 - unitSize + 1;
			while (i <= index1)
			{
				il = lst.begin();
				std::advance(il, i);
				tmp = *il;
				il2 = lst.begin();
				std::advance(il2, i + unitSize);
				*il = *il2;
				*il2 = tmp;
				i++;
			}
		}
		index1 += indexIncrement;
		index2 += indexIncrement;
	}
	if (2 * unitSize < lst.size())
		ford_johnson_sort(lst, 2 * unitSize);
	std::list<int>	secondaryChain;
	std::list<int>	mainChain;
	i = 0;
	while (i < unitSize)
	{
		il = lst.begin();
		std::advance(il, i);
		mainChain.push_back(*il);
		i++;
	}
	i = 0;
	size_t	j = 0;
	std::list<int>::iterator	jl = lst.begin();
	while (i < unitQty)
	{
		j = i * unitSize;
		jl = lst.begin();
		std::advance(jl, j);
		while (j < (i + 1) * unitSize)
		{
			if (i % 2)
				mainChain.push_back(*jl);
			else
				secondaryChain.push_back(*jl);				
			j++;
			jl = lst.begin();
			std::advance(jl, j);
		}
		i++;
	}
	lst.clear();
	size_t	jacobsthalNumbers[28] = {3, 5, 11, 21, 43, 85, 171, 341, 683, \
	1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, \
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, \
	178956971, 357913941};
	j = 0;
	while (jacobsthalNumbers[j] <= secondaryChain.size() && j < 28)
		j++;
	i = 0;
	size_t	posRight;
	size_t	posLeft;
	posLeft = 1;
	std::list<int>	unitB;
	size_t	k;
	std::list<int>::iterator	kl = secondaryChain.begin();
	while (i <= j)
	{
		posRight = jacobsthalNumbers[i];
		if (i > 0)
			posLeft = jacobsthalNumbers[i - 1];
		while (posRight > posLeft)
		{
			if (posRight <= (secondaryChain.size() / unitSize))
			{
				unitB.clear();
				k = (posRight - 1) * unitSize;
				while (k < posRight * unitSize)
				{
					kl = secondaryChain.begin();
					std::advance(kl, k);
					unitB.push_back(*kl);
					k++;
					kl = secondaryChain.begin();
					std::advance(kl, k);
				}
				binary_insert(mainChain, unitB);
			}
			posRight--;
		}
		i++;
	}
	if (!spareUnit.empty())
	{
		binary_insert(mainChain, spareUnit);
	}
	lst = mainChain;
}

void	pmergeme(std::vector<int> &vec)
{
	std::list<int>	lst(vec.begin(), vec.end());
	std::cout << "Before: " << vec << std::endl;
	struct timeval	s_time_before;
	struct timeval	s_time_after;
	struct timeval	s_time_elapsed;
	if (gettimeofday(&s_time_before, NULL) < 0)
		throw std::runtime_error(strerror(errno));
	ford_johnson_sort(vec);
	if (gettimeofday(&s_time_after, NULL) < 0)
		throw std::runtime_error(strerror(errno));
	
	std::cout << "After: " << vec << std::endl;
	
	timersub(&s_time_after, &s_time_before, &s_time_elapsed);
	std::cout << "Time to process a range of " << vec.size() << " elements using" << std::endl;
	std::cout << "-std::vector<int> :	" << s_time_elapsed.tv_sec << " s, " << s_time_elapsed.tv_usec << " μs." << std::endl;

	if (gettimeofday(&s_time_before, NULL) < 0)
		throw std::runtime_error(strerror(errno));
	ford_johnson_sort(lst);
	if (gettimeofday(&s_time_after, NULL) < 0)
		throw std::runtime_error(strerror(errno));
	timersub(&s_time_after, &s_time_before, &s_time_elapsed);
	std::cout << "-std::list<int> :	" << s_time_elapsed.tv_sec << " s, " << s_time_elapsed.tv_usec << " μs." << std::endl;
}
