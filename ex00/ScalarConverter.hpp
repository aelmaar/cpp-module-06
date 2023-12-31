/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:10:17 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/23 12:46:54 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cfloat>
# include <cmath>
# include "utils.hpp"

typedef struct s_type_convert {
    std::string end_type;
    double value;
    bool is_numerical;
} t_type_convert;

class ScalarConverter
{
    static void convertToChar(t_type_convert &type);
    static void convertToInt(t_type_convert &type);
    static void convertToFloat(t_type_convert &type);
    static void convertToDouble(t_type_convert &type);
    ScalarConverter();
    public:
        static void convert(const std::string str_literal);
};

#endif
