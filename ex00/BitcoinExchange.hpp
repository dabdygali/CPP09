/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/15 16:40:48 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BITCOINEXCHANGE_HPP_
	#define _BITCOINEXCHANGE_HPP_

	#include <map>
	#include <string>
	#include <fstream>

	#define DATABASE_FILE	"data.csv"
	#define DATABASE_HEADER	"date,exchange_rate"
	#define REQUEST_HEADER	"date | value"
	
	class BitcoinExchange : public std::map<std::string, float>
	{
		private:
		public:
			BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &src);
			virtual ~BitcoinExchange();
			BitcoinExchange	&operator=(const BitcoinExchange &rhs);
			void			addElement(const std::string &str);
			void			processRequest(std::ifstream &in);
	};

	std::ifstream	&operator>>(std::ifstream &in, BitcoinExchange &rhs);
	
#endif
