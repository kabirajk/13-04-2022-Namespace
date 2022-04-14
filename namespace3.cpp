#include <iostream>

namespace GLOBAL
{
    namespace pv1
    {
        void print()
        {
            std::cout<<"this is from namespace pv1\n";
        }
    }
    namespace pv2
    {
        void print()
        {
            std::cout<<"this is from namespace pv2\n";
        }
    }
}

int main()
{
    GLOBAL::pv1::print();
    GLOBAL::pv2::print();
    return 0;
}