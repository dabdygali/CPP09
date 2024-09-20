/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:13:07 by dabdygal          #+#    #+#             */
/*   Updated: 2024/09/20 10:07:50 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <cctype>
#include <functional>
#include <string>
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
	std::string	tmp("Operator not recognised: ");
	tmp.push_back(c);
	if (isdigit(c))
	{
		push(c - '0');
		return;
	}
	switch (c)
	{
		case '+':
			performBinaryOperation(std::plus<float>());
			return;
		case '-':
			performBinaryOperation(std::minus<float>());
			return;
		case '*':
			performBinaryOperation(std::multiplies<float>());
			return;
		case '/':
			if (top() == 0)
				throw std::invalid_argument("Error: Division by zero");
			performBinaryOperation(std::divides<float>());
			return;
		default:
			throw std::invalid_argument(tmp);
	}
}

float	RPN::evaluate(const char *str)
{
	if (str == NULL || str[0] == '\0')
		throw std::invalid_argument("No arguments passed");
	int	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if (str[i + 1] != ' ' && str[i + 1] != '\0')
				throw std::invalid_argument("Wrong format. Supported: positive single digit numbers, operators +, -, /, *");
			processToken(str[i]);
		}
		i++;
	}
	return top();
}
