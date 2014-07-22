#include<iostream>
#include<string.h>
using namespace std;
class String
{
    friend std::ostream& operator <<(std::ostream &os,const String &str);
    public:
        String():size_(0)
        {
            str_=new char;
            str_[0]='\0';
        }
        String(const String &str);
        int size()
        {
            return size_;
        }
        ~String();
    private:
        char *str_;
        int size_;
};
std::ostream& operator << (std::ostream &os,const String &str)
{
    os<<str.str_;
    return os;
}
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
int main(int argc,char** argv)
{
    String s1;
    cout<<s1<<endl;
    cout<<s1.size()<<endl;
}
