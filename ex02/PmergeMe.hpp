/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:14:17 by dabdygal          #+#    #+#             */
/*   Updated: 2024/09/13 10:21:36 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _PMERGEME_HPP_
	#define _PMERGEME_HPP_

	#include <vector>
	#include <iostream>

	void			pmergeme(std::vector<int> &vec);
	std::ostream	&operator<<(std::ostream &out, std::vector<int> &rhs);
#endif
