/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:41:46 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/20 11:29:16 by dabdygal         ###   ########.fr       */
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
	};
	
#endif
