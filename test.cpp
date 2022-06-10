


#include <iostream>     // std::cout
#include <algorithm>    // std::swap
#include "vector.hpp"       // std::vector

int main () {

  int x=10, y=20;                              // x:10 y:20
  std::swap(x,y);                              // x:20 y:10

  ft::Vector<int> foo (4,x), bar (6,y);       // foo:4x20 bar:6x10
  ft::swap(foo,bar);                          // foo:6x10 bar:4x20

  std::cout << "foo contains:";
  for (ft::Vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}