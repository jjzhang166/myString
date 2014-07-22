#include "String.h"
#include<iostream>
#include<string.h>
using namespace std;
String::String():str_(new char[1])
{
    str_[0]='\0';
    size_=0;
}
String::String(const char *s):str_(new char[strlen(s)+1])
{
    ::strcpy(str_,s);
}
String::String(const String &s):str_(new char[s.size()+1])
{
    ::strcpy(str_,s.str_);
}
String::~String()
{
    delete[] str_;
}

String &String::opeator=(const String &s)
{
    if(this!=&s)
    {
        delete[] str_;
        str_=new char[s.size()+1];
        ::strcpy(str_,s.str_);
    }
    return *this;
}
String &String::operator+=(const char *s)
{
    return operator+=(String(s));
}
String &String::operator+=(const String &s)
{
    //先申请足够的内存空间，存放最终的结果
    char *pt=new char[size()+s.size()+1];
    ::strcpy(pt,str_);
    ::strcat(pt,s.str_);
    //先释放之前的内存
    delete str_;
    str_=pt;
    return *this;
}
void String::debug() const
{
    cout<<str_<<endl;
}

size_t String::size() const
{
    return ::strlen(str_);
}
bool operator<(const String &s1,const String &s2)
{
    return strcmp(s1.str_,s2.str_)<0;
}
bool operator>(const String &s1,const String &s2)
{
    return s2<s1;
}
bool operator<=(const String &s1,const String &s2)
{
    return !(s1>s2);
}
bool operator>=(const String &s1,const String &s2)
{
    return !(s1<s2);
}
bool operator==(const String &s1,const String &s2)
{
    return ::strcmp(s1.str_,s2,str_)==0;
}
bool operator!=(const String &s1,const String &s2)
{
    return !(s1==s2);
}
char &String::operator[](size_t index)
{
    return str_[index];
}
