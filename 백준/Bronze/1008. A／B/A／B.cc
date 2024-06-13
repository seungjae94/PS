#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    std::cin >> a;
    std::cin >> b;
    
    std::cout.precision(10);
    std::cout << static_cast<double>(a) / b;
}