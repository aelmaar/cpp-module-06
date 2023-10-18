/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 09:49:50 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/18 10:33:17 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t Serialize::serialize(Data* ptr) {
    uintptr_t int_ptr = reinterpret_cast<uintptr_t>(ptr);
    return (int_ptr);
}

Data* Serialize::deserialize(uintptr_t raw) {
    Data *data_ptr = reinterpret_cast<Data*>(raw);
    return (data_ptr);
}
