/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/13 16:39:13 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BITCOINEXCHANGE_HPP_
	#define _BITCOINEXCHANGE_HPP_

	#include <map>
	#include <string>
	#include <fstream>

	#define DATABASE_FILE	"data.csv"
	
	class BitcoinExchange : public std::map<std::string, float>
	{
		private:
		public:
			BitcoinExchange();
			BitcoinExchange(std::ifstream &ifs);
			BitcoinExchange(const BitcoinExchange &src);
			virtual ~BitcoinExchange();
			BitcoinExchange	&operator=(const BitcoinExchange &rhs);
	};
	
#endif
