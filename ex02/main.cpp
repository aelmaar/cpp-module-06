/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:04:21 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/18 15:05:58 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomBase.hpp"

int main(void)
{
    RandomBase random_base;
    Base *bPtr = random_base.generate();
    
    Base &bRef = *bPtr;
    random_base.identify(bPtr);
    random_base.identify(bRef);
    return (EXIT_SUCCESS);
}
