#include <string>
#include <iostream>

class Hello {

};

int main()
{
    std::string s = "Hello World";
    std::cout << s << std::endl;
    Hello* h = new Hello();
    return 0;
}