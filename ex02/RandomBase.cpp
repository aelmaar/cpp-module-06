/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomBase.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:13:15 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/18 15:41:37 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomBase.hpp"

RandomBase::RandomBase() {
    generateBase[0] = &RandomBase::createBaseA;
    generateBase[1] = &RandomBase::createBaseB;
    generateBase[2] = &RandomBase::createBaseC;
}

RandomBase::RandomBase(RandomBase const &old_obj) {
    generateBase[0] = old_obj.generateBase[0];
    generateBase[1] = old_obj.generateBase[1];
    generateBase[2] = old_obj.generateBase[2];
}

RandomBase &RandomBase::operator=(RandomBase const &other) {
    (void)other;
    return (*this);
}

RandomBase::~RandomBase() {}

Base *RandomBase::getGenerateBase(int index) {
    return ((this->*generateBase[index])());
}

Base *RandomBase::createBaseA(void) { return (new A()); }

Base *RandomBase::createBaseB(void) { return (new B()); }

Base *RandomBase::createBaseC(void) { return (new C()); }

Base *RandomBase::generate(void) {
    int randomNumberBase;

    std::srand(std::time(0));
    randomNumberBase = rand() % BASES;
    return ((this->*generateBase[randomNumberBase])());
}

void RandomBase::identify(Base* p) {
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);
    if (a)
        std::cout << "Base A" << std::endl;
    if (b)
        std::cout << "Base B" <<std::endl;
    if (c)
        std::cout << "Base C" <<std::endl;
}

void RandomBase::identify(Base &p) {
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Base A" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Base B" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Base C" << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
}
