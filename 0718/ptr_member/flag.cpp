#include<iostream>
#include"flag.h"
Flag::Flag(int v)
{
    i=v;
}
Flag::~Flag()
{
    std::cout<<"delete the value"<<std::endl;
}
