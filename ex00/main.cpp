/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:32:24 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/17 17:56:29 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {

    if (argc == 2)
    {
        std::string str_literal = argv[1];
        ScalarConverter::convert(str_literal);
    }
    else
        std::cout << "Usage: ./convert [literal]" << std::endl;
    return (EXIT_SUCCESS);
}
