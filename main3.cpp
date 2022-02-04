#include "map/bst.hpp"
#include "map/pair.hpp"

void    foo(void)
{
    ft::BST<ft::pair<int, int>, std::less<int> >    myfirstTree;
    int arr[] = {3,2,4};

    for (int i = 0; i < 3; i++)
        myfirstTree.insert(&(myfirstTree.root), myfirstTree.node_new(ft::make_pair(arr[i], 42)));

    

    // myfirstTree.tree_delete(&(myfirstTree.root),myfirstTree.tree_search((myfirstTree.root),33));

    std::cout << "tt" << std::endl;
    // std::cout << myfirstTree.root->parent->right->data << std::endl;

    myfirstTree.tree_debug(myfirstTree.root);

}

int     main()
{
    foo();
    // system("leaks a.out");

    return 0;
}