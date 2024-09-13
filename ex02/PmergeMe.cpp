/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:46:00 by dabdygal          #+#    #+#             */
/*   Updated: 2024/09/13 11:28:29 by dabdygal         ###   ########.fr       */
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

static void	ford_johnson_sort(std::vector<int> &vec)
{
}

static void	ford_johnson_sort(std::list<int> &lst)
{
}

void	pmergeme(std::vector<int> &vec)
{
	std::list<int>	lst(vec.begin(), vec.end());
	std::cout << "Before: " << vec;
	struct timeval	s_time_before;
	struct timeval	s_time_after;
	struct timeval	s_time_elapsed;
	if (gettimeofday(&s_time_before, NULL) < 0)
		throw std::runtime_error(strerror(errno));
	ford_johnson_sort(vec);
	if (gettimeofday(&s_time_after, NULL) < 0)
		throw std::runtime_error(strerror(errno));
	
	std::cout << "After: " << vec;
	
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
