/*
 *  placeholder.cpp
 *  Created on: 29 10 2018 г.
 *  Author: Dmitry Donskih
 *
 *  This file is licensed under the terms of MIT license.
 *  Be free to use, modify, fork, etc. this file.
 *  Copyright © 2018 Dmitry Donskih. All rights reserved.
 */

#include <iostream>

#include "cppfeatures.hpp"

/**/
/* __attribute__((weak)) in GCC */
#ifndef UFW_WEAK_IMPL
#define UFW_WEAK_IMPL __attribute__((weak))
#endif

#define USE_PLACEHOLDER_MAIN
#ifdef USE_PLACEHOLDER_MAIN

UFW_WEAK_IMPL int main(int argc, char* argv[])
{
    std::cout << "Compiler features check" << std::endl;
    std::cout << "C++ version: " << __cplusplus << std::endl;
#if __STDCPP_THREADS__ == 1
    std::cout << "Standart library has thread support" << std::endl;
#endif
    cxxfeatures::print();
}

#endif
