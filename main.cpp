#include <vector>
#include "vector.hpp"

#include <iostream>

#include "random_access_iterator.hpp"
// int main()
// {
//     ft::vector<int> c(5);

//     c.push_back(5);
//     c.push_back(54);

//     ft::vector<int>::iterator it = c.begin();
//     ft::vector<int>::iterator ite = c.end();
//     while(it != ite)
//     {
//         std::cout << *it << std::endl;
//         it++;
//     }
    // ft::vector<int>::iterator cc =c.begin();
    // *cc++;
    // // cc-= 1;
    // std::cout << *cc <<  std::endl;
    // std::cout << c[0] <<  std::endl;

// int main ()
// {
//   ft::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin()+5);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
// int main ()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
// std::cout << ' ' << bar.size();std::cout << '\n';
//   return 0;
// }

int main ()
{
  std::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}


