#include <vector>

#include <iostream>

int main()
{
    std::vector<int> c;

    c.push_back(5);
    c.push_back(54);

    std::vector<int>::iterator cc =c.begin();
    *cc++;
    // cc-= 1;
    std::cout << *cc <<  std::endl;
    std::cout << c[0] <<  std::endl;

}