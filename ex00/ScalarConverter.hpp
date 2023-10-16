/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:10:17 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/16 15:10:21 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

// typedef struct str_literal {
//     char *end;
//     double value;
//     bool is_float;
// } str_literal;

class ScalarConverter
{
    static void convertToChar(double value);
    static void convertToInt(double value);
    static void convertToFloat(double value);
    static void convertToDouble(double value);
    public:
        static void convert(const std::string str_literal);
};

#endif
