/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:09:43 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/20 11:35:06 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <exception>
#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	RPN	calculator;

	if (argc != 2)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	try
	{
		calculator.evaluate(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << calculator.top() << std::endl;
	return EXIT_SUCCESS;	
}
