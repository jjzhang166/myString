#ifndef _STRING_H
#define _STRING_H
#include<iostream>
#include<string.h>
class String
{
    friend std::ostream &operator<<(std::ostream & , const String &);
    public:
        String():size_(0)
        {
            str_=new char;
            str_[0]='\0';
        }
        String(const String &);//赋值构造函数
        int size()
        {
            return size_;
        }
        ~String();
    private:
        char *str_;
        int size_;
};
inline std::ostream &operator<<(std::ostream &os,const String &str)
{
    os<<str.str_;
    return os;
}
#endif
