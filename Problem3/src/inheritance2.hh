/**
 * @file: inheritance2.hh
 * @author: Sang Jae Park <mainpower4309@gmail.com>
 * 
 */
#ifndef __INHERITANCE2_HH__
#define __INHERITANCE2_HH__

#include <iostream>

class James{
public:
    void func1(){
        std::cout << "J func1" << std::endl;
    }

    virtual void func3(){
        std::cout << "J func3" << std::endl;
    } 
};

class Richard : public James{
public:
    virtual void func1(){
        std::cout << "R func1" << std::endl;
    }
    
    virtual void func3(){
        std::cout << "R func3" << std::endl;
    } 
};


class Donard : public Richard {
public:
    virtual void func2(){
        std::cout << "D func2" << std::endl;
    }
    
    void func4(){
        std::cout << "D func4" << std::endl;
    } 
};


class Edward : public Donard{
public:

    virtual void func2(){
        std::cout << "E func2" << std::endl;
    }

    virtual void func4(){
        std::cout << "E func4" << std::endl;
    }
};

#endif