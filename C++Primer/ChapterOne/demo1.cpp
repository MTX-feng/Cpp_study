#include <iostream>

int main()
{
    std::cout << "请输入两个数字" << std::endl;
    int n1 = 0, n2 = 0;
    std::cin >> n1 >> n2;
    std::cout << "两数之和等于" << n1+n2 << std::endl;
    
    return 0;
}