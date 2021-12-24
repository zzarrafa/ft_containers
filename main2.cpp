#include <vector>
#include <iostream>

int     main()
{
    std::vector<int> vec1(6,6);
    std::cout << vec1.max_size() << std::endl;
    vec1.reserve(4611686018427387903 + 1);
    return 0;
}