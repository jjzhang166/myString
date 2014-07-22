
#include <string.h>
#include<iostream>
#include "String.h"
using namespace std;
String::String(const String &str)
{
    size_=str.size_;
    str_=new char[strlen(str.str_)+1];
    if(str_!=NULL)
    {
        strcpy(str_,str.str_);
    }
}
String::~String()
{
    delete [] str_;
}
