/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:52:23 by dabdygal          #+#    #+#             */
/*   Updated: 2024/09/13 10:41:40 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <sstream>

static void	argsToVector(const char *const *argv, std::vector<int> &vec)
{
	if (argv == NULL || *argv == NULL)
		return;
	std::stringstream	sio;
	while (*argv != NULL)
	{
		sio << *argv;
		if (*(argv + 1) != NULL)
			sio << ' ';
		argv++;
	}
	int	i;
	while (sio.good())
	{
		sio >> i;
		if (sio.fail() || i < 0)
			throw std::invalid_argument("Error: data is not recognised as positive integer");
		vec.push_back(i);
	}
}

int	main(int argc, char *argv[])
{
	static_cast<void>(argc);
	std::vector<int>	vec;
	try
	{
		argsToVector(argv + 1, vec);
		pmergeme(vec);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
