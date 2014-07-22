#include"flag.h"
class U_Ptr
{
    public:
        friend class Student;
        U_Ptr(Flag *p);
        virtual ~U_Ptr();
    private:
        Flag *books;
        unsigned int use;
};
