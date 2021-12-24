#include "vector.hpp"
#include <vector>
int main(){
          ft::Vector<std::string>::iterator ft_it;
        std::vector<std::string>::iterator it;        
  	std::vector<std::string> v;
            ft::Vector<std::string> ft_v;
            it = v.insert(v.begin(), "hello");
            ft_it = ft_v.insert(ft_v.begin(), "hello");
            ft_it->length();

        }
