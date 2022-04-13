#include <iostream>
namespace String
{
    int len(std::string s)
    {
        int i=0;
        while(s[i])
            i++;
        return i;
    }
}

int main ()
{
  std::string My_string = "Im Kabiraj kabi";
  std::cout<<String::len(My_string)<<std::endl;
  std::cout<<My_string.length()<<std::endl;
  return 0;
}
