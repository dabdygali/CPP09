/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:39 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/15 16:55:57 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << argv[0] << ": Wrong number of arguments" << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream	databaseIStream(DATABASE_FILE);
	if (!databaseIStream.good())
	{
		std::cerr << argv[0] << ": Could not open database file \"" << DATABASE_FILE << '"' << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream	inputFileIStream(argv[1]);
	if (!inputFileIStream.good())
	{
		std::cerr << argv[0] << ": Could not open file \"" << argv[1] << '"' << std::endl;
		return EXIT_FAILURE;
	}

	BitcoinExchange	bitcoinPriceHistory;
	databaseIStream >> bitcoinPriceHistory;
	if (databaseIStream.fail())
	{
		std::cerr << argv[0] << ": Error parsing file \"" << DATABASE_FILE << '"' << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		bitcoinPriceHistory.processRequest(inputFileIStream);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
