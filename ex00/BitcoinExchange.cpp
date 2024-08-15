/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:45:48 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/15 17:11:41 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <cctype>
#include <sstream>
#include <iostream>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : std::map<std::string, float>(src)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this !=  &rhs)
		std::map<std::string, float>::operator=(rhs);
	return *this;
}

static bool	isDate(const std::string &str)
{
	if (str.size() != 10)
		return false;
	int	i = 0;
	while (i < 10)
	{
		if (i == 4 || i == 7)
		{
			if (str[i] != '-')
				return false;			
		}
		else if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

void	BitcoinExchange::addElement(const std::string &str)
{
	size_t	commaPosition;
	commaPosition = str.find_first_of(',');
	if (commaPosition == str.npos)
		throw std::invalid_argument("Line \"" + str + "\": comma(',') not found");
	
	std::string	date(str, 0, commaPosition);
	if (!isDate(date))
		throw std::invalid_argument("Line \"" + str + "\": date is ill formed");
	
	float				price;
	std::istringstream	iss(str.substr(commaPosition + 1));
	iss >> price;
	if (iss.fail() || !iss.eof())
		throw std::invalid_argument("Line \"" + str + "\": price is ill formed");
	
	if (!insert(std::pair<std::string, float>(date, price)).second)
		throw std::invalid_argument("Line \"" + str + "\": date already exist");
}

void	BitcoinExchange::processRequest(std::ifstream &in)
{
	std::string	str;
	std::getline(in, str);
	if (!in.good())
		throw std::invalid_argument("Request ill formed");
	if (str.compare(REQUEST_HEADER))
	{
		in.setstate(in.failbit);
		throw std::invalid_argument("Line \"" + str + "\": header is ill formed");
	}
	while (in.good())
	{
		std::getline(in, str);
		if (in.eof() && str.empty())
		{
			in.clear(in.eofbit);
			return;
		}
		processRequestEntry(str);
	}
}

std::ifstream	&operator>>(std::ifstream &in, BitcoinExchange &rhs)
{
	rhs.clear();
	std::string	str;
	std::getline(in, str);
	if (!in.good())
		return in;
	if (str.compare(DATABASE_HEADER))
	{
		in.setstate(in.failbit);
		return in;
	}
	while (in.good())
	{
		std::getline(in, str);
		try
		{
			rhs.addElement(str);
		}
		catch (std::exception &e)
		{
			if (in.eof() && str.empty())
				in.clear(in.eofbit);
			else
				in.setstate(in.failbit);
			return in;
		}
	}
	return in;
}
