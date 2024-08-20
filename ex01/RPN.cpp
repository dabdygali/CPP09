/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:13:07 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/20 12:02:26 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <cctype>
#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src) : stack(src.c)
{
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &rhs)
{
	c = rhs.c;
	return *this;
}

void	RPN::processToken(char c)
{
	if (isdigit(c))
	{
		push(c - '0');
		return;
	}
	
}

float	RPN::evaluate(const char *str)
{
	if (str == NULL)
		throw std::invalid_argument("No arguments passed");
	int	i = 0;
	while (str[0] != '\0')
	{
		if (str[i] != ' ')
		{
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				throw std::invalid_argument("Wrong format. Supported: positive single digit numbers, operators +, -, /, *");
			processToken(str[i]);
		}
		i++;
	}
}
