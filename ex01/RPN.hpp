/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:41:46 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/21 13:19:11 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _RPN_HPP_
	#define _RPN_HPP_

	#include <stack>
	
	class RPN : public std::stack<float>
	{
		private:
		public:
			RPN();
			RPN(const RPN &src);
			virtual ~RPN();
			RPN &operator=(const RPN &rhs);
			float	evaluate(const char *str);
			void	processToken(char c);
			template <typename BinaryOperation>
			void	performBinaryOperation(BinaryOperation binary_op);
	};

	template <typename BinaryOperation>
	void	RPN::performBinaryOperation(BinaryOperation binary_op)
	{
		if (size() < 2)
			throw std::invalid_argument("Operation impossible: not enough operands");
		float	y = top();
		pop();
		float	x = top();
		pop();

		float result = binary_op(x, y);
		push(result);
	}
	
#endif
