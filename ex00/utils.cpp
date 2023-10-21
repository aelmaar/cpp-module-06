/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:00:06 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/21 15:13:55 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int calc_precision_len(const std::string &str_literal)
{
    int precision_len;
    size_t locate_f = str_literal.find("f");
    try
    {
        precision_len = str_literal.substr(str_literal.find(".")).length() - 1;
        if (locate_f != std::string::npos && precision_len > 1)
            precision_len--;
    }
    catch(const std::exception& e)
    {
        precision_len = 1;
    }
    return (precision_len == 0 ? 1 : precision_len);
}
