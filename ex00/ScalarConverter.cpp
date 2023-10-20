/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:10:15 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/20 22:52:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string str_literal) {
    t_type_convert type;
    char *end;

    type.is_numerical = true;
    type.is_float = false;
    type.value = strtod(str_literal.c_str(), &end);
    type.end_type = end;
    if (type.end_type.length() > 1)
        type.is_numerical = false;
    if (type.end_type == "f" && str_literal.length() > 1 
    && (str_literal.find('.') != std::string::npos))
        type.is_float = true;
    convertToChar(type, str_literal);
    convertToInt(type, str_literal);
    convertToFloat(type, str_literal);
    convertToDouble(type, str_literal);
}

// Convert to char
void ScalarConverter::convertToChar(t_type_convert &type, const std::string &str_literal) {
    if (type.value > CHAR_MAX || type.value < CHAR_MIN || type.end_type.length() > 1
    || (!type.is_float && !type.end_type.empty()))
        std::cout << "char: Impossible" << std::endl;
    else if (type.end_type == str_literal)
        std::cout << "char: \'" << type.end_type << "\'" << std::endl;
    else if (!isprint(type.value))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: \'" << static_cast<char>(type.value) << "\'" << std::endl;
}

// Convert to int
void ScalarConverter::convertToInt(t_type_convert &type, const std::string &str_literal) {
    if (type.value > INT_MAX || type.value < INT_MIN || !type.is_numerical 
    || std::isinf(type.value) || std::isnan(type.value) 
    || (!type.is_float && !type.end_type.empty()))
        std::cout << "int: Impossible" << std::endl;
    else if (type.end_type == str_literal)
        std::cout << "int: " << static_cast<int>(type.end_type[0]) << std::endl;
    else
        std::cout << "int: " << static_cast<int>(type.value) << std::endl;
}

// Convert to float
void ScalarConverter::convertToFloat(t_type_convert &type, const std::string &str_literal) {
    if ((std::isinf(type.value) || std::isnan(type.value)) && type.is_numerical)
        std::cout << "float: " << type.value << "f" << std::endl;
    else if (!type.is_numerical || (!type.is_float && !type.end_type.empty()))
        std::cout << "float: Impossible" << std::endl;
    else if (type.end_type == str_literal)
        std::cout << "float: " << static_cast<float>(type.end_type[0]) << ".0f" << std::endl;
    else if (static_cast<float>(type.value) == static_cast<int>(type.value))
        std::cout << "float: " << static_cast<float>(type.value) << ".0f" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(type.value) << "f" << std::endl;
}

// Convert to double
void ScalarConverter::convertToDouble(t_type_convert &type, const std::string &str_literal) {
    if ((std::isinf(type.value) || std::isnan(type.value)) && type.is_numerical)
        std::cout << "double: " << type.value << std::endl;
    else if (!type.is_numerical || (!type.is_float && !type.end_type.empty()))
        std::cout << "double: Impossible" << std::endl;
    else if (type.end_type == str_literal)
        std::cout << "double: " << static_cast<double>(type.end_type[0]) << ".0" << std::endl;
    else if (static_cast<double>(type.value) == static_cast<int>(type.value))
        std::cout << "double: " << static_cast<double>(type.value) << ".0" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(type.value) << std::endl;
}
