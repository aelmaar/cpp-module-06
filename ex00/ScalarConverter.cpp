/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:10:15 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/16 15:29:15 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string str_literal) {
    char *end;
    double end_value;
    bool is_float = false;
    bool is_alphabet = false;

    end_value = strtod(str_literal.c_str(), &end);
    // 1- Check if it's not numerical (include alphabets) set is_alphabet to true
    // 2- Check if it's float set is_float to true
    // 3- Then prints the type to the other types (char, int, float, double)
}

