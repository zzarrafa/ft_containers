#include <iostream>       // std::cout
#include "vector.hpp"         // std::stack
#include <string>
template<class T>
void  debug(ft::Vector<T> myvec)
{
  std::cout << "[";
  for(int i = 0; i < myvec.size()-1; i++)
  {
    std::cout << myvec[i] << ", ";
  }
  std::cout << myvec[myvec.size()-1] << "]" << std::endl;
}
int main(void)
{
  ft::Vector<std::string> ft_v(20, "string");

  ft_v.insert(ft_v.begin() + 10, 15, "hello");

  debug<std::string>(ft_v);

  return 0;
}