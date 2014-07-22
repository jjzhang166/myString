/*************************************************************************
	> File Name: String.h
	> Author: xuxiaoqiang
	> Mail:353271054@qq.com 
	> Created Time: 2014年07月18日 星期五 15时40分59秒
 ************************************************************************/

#ifndef _STRING_H
#define _STRING_H
#include<stddef.h>
#include<iostream>
class String
{
    friend std::ostream& operator<<(std::ostream &,const String &);
    friend std::istream& operator>>(std::istream &,const String &);
   
    friend String operator+(const String &,const Stromg &);
    friend String operator+(const String &,const char *);
    friend String operator+(const char*,const String &);

    friend bool operator<(const String &,const String &);
    friend bool operator>(const String &,const String &);
    friend bool operator<=(const String &,const String &);
    friend bool operator>=(const String &,const String &);
    friend bool operator==(const String &,const String &);
    friend bool operator!=(const String &,cosnt String &);
    public:
        String();
        String(const char *);
        String(const String &);
        ~String();

        String &operator=(const char *);
        String &operator=(const String &);

        String &operator+=(const char *);
        String &operator+=(const String &);

        char &operator[](size_t index);
        char operator[](size_t index) const;

        void debug() const;
        size_t size() const;
        const char *c_str() const;
    private:
        char *str_;
        int size_;

};
inline std::ostream &operator<<(std::ostream &os,const String &s)
{
    os<<s.str_;
    return os;
}
inline std::istream &operator>>(std::istream &is ,String &s)
{
    //重载输入操作符，需要定义一个buffer
    char buf[1024];
    is>>buf;
    if(is)
    {
        s=buf;//调用已经定义好的函数
    }
    return is;
}
//+操作符
inline String operator+(const String &s1,const String s2)
{
    //考虑是否能用构造函数或者复制构造函数 
    //加法不改变原来的对象，所以这里生成一个新的局部对象
    String ret(s1);
    ret+=s2;
    return ret;
}

inline String operator+(const String &s1,const char *s2)
{
    //同样采用调用其他的版本
    return s1+String(s2);
}
inline String operator+(const char *s1,const String &s2)
{
    return String(s1)+s2;
}
/*
 * 这种重载版本是错误的。
inline String operator+(cont char *s1,const char *s2)
{
    return String(s1)+string(s2);
}
*/




#endif

