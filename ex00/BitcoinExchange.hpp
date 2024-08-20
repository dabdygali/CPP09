/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdygal <dabdygal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:36 by dabdygal          #+#    #+#             */
/*   Updated: 2024/08/19 10:00:07 by dabdygal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef _BITCOINEXCHANGE_HPP_
	#define _BITCOINEXCHANGE_HPP_

	#include <map>
	#include <string>
	#include <fstream>

	#define DATABASE_FILE			"data.csv"
	#define DATABASE_HEADER			"date,exchange_rate"
	#define REQUEST_HEADER			"date | value"
	#define REQUEST_DELIMETER		" | "
	#define REQUEST_DELIMETER_SIZE	sizeof(REQUEST_DELIMETER)
	
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
			void			processRequestEntry(const std::string &str);
	};

	std::ifstream	&operator>>(std::ifstream &in, BitcoinExchange &rhs);
	
#endif
