#include<iostream>
#include"student.h"
using namespace std;
int main()
{
    int *b=new int(34);
    Student s(b);
    delete b;
    cout<<(*(s.books))<<endl;
    return 0;
}
