#include <vector>
#include "vector.hpp"

#include <iostream>

#include "iterators.hpp"
int main()
{
    ft::vector<int> c(5);

    c.push_back(5);
    c.push_back(54);

    ft::vector<int>::iterator it = c.begin();
    ++it;  
    std::cout << *it << std::endl;
    // std::vector<int>::iterator cc =c.begin();
    // *cc++;
    // // cc-= 1;
    // std::cout << *cc <<  std::endl;
    // std::cout << c[0] <<  std::endl;

}