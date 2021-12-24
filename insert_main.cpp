#include "vector.hpp"
#include <iostream>


template <class T>
void    debug(ft::Vector<T> vec1){
    for (int i=0; i < vec1.size(); i++){
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;
}

int     main()
{
    ft::Vector<int> myvec(20, 42);
    myvec.insert(myvec.begin()+10, 100, 69);
    debug<int>(myvec);

    return 0;
}