/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomBase.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:13:18 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/18 15:41:00 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMBASE_HPP
# define RANDOMBASE_HPP

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <iostream>

# define BASES 3

class RandomBase {
    typedef Base* (RandomBase::*createBase)();
    Base *createBaseA();
    Base *createBaseB();
    Base *createBaseC();
    createBase generateBase[BASES];
    public:
        RandomBase();
        RandomBase(RandomBase const &old_obj);
        RandomBase &operator=(RandomBase const &other);
        ~RandomBase();
        Base *getGenerateBase(int index);
        Base * generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif
