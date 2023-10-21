/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:10:15 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/21 15:46:15 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

void ScalarConverter::convert(const std::string str_literal) {
    t_type_convert type;
    char *end;

    type.is_numerical = true;
    type.value = strtod(str_literal.c_str(), &end);
    type.end_type = end;

    if (str_literal.empty() 
        || type.end_type.length() > 1 
        || (!type.end_type.empty() && type.end_type != "f" && type.end_type != str_literal)
        || (str_literal.length() > 1 && type.end_type == "f" && str_literal.find('.') == std::string::npos 
            && !(std::isnan(type.value) || std::isinf(type.value))))
    {
        type.is_numerical = false;
    }

    if (type.end_type == str_literal && str_literal.length() == 1)
        type.value = static_cast<double>(str_literal[0]);

    std::cout << std::fixed << std::setprecision(calc_precision_len(str_literal));
    convertToChar(type);
    convertToInt(type);
    convertToFloat(type);
    convertToDouble(type);
}

// Convert to char
void ScalarConverter::convertToChar(t_type_convert &type) {
    if (type.value > CHAR_MAX || type.value < CHAR_MIN || !type.is_numerical || std::isnan(type.value))
        std::cout << "char: Impossible" << std::endl;
    else if (!isprint(type.value))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: \'" << static_cast<char>(type.value) << "\'" << std::endl;
}

// Convert to int
void ScalarConverter::convertToInt(t_type_convert &type) {
    if (type.value > INT_MAX || type.value < INT_MIN || !type.is_numerical || std::isnan(type.value))
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(type.value) << std::endl;
}

// Convert to float
void ScalarConverter::convertToFloat(t_type_convert &type) {
    if ((std::isinf(type.value) || std::isnan(type.value)) && type.is_numerical)
        std::cout << "float: " << type.value << "f" << std::endl;
    else if (!type.is_numerical)
        std::cout << "float: Impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(type.value) << "f" << std::endl;
}

// Convert to double
void ScalarConverter::convertToDouble(t_type_convert &type) {
    if ((std::isinf(type.value) || std::isnan(type.value)) && type.is_numerical)
        std::cout << "double: " << type.value << std::endl;
    else if (!type.is_numerical)
        std::cout << "double: Impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(type.value) << std::endl;
}
