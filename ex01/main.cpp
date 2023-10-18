/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:05:28 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/18 10:35:24 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(void)
{
    Data data_obj;
    uintptr_t int_obj;
    
    data_obj.number = 10;
    int_obj = Serialize::serialize(&data_obj);
    Data *data_ptr = Serialize::deserialize(int_obj);

    std::cout << "The data pointer address: " << data_ptr << std::endl;
    std::cout << "The data object address: " << &data_obj << std::endl;
    std::cout << "The data pointer value: " << data_ptr->number << std::endl;
    std::cout << "The data object value: " << data_obj.number << std::endl;

    return (EXIT_SUCCESS);
}
