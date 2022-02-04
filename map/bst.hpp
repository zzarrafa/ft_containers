/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:14:16 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/02/04 12:46:03 by zineb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <memory>
#include <string>
#include <iostream>
#include <functional>
#include "pair.hpp"



namespace ft
{
    template< class T>
    struct Node{
        typedef Node<T> node;
        typedef T  value_type;
        
        // Node(value_type _data){
        //     data = _data;
        //     left = 0;
        //     right = 0;
        //     parent = 0;
        // }
        
        value_type data;
        node*   left;
        node*   right;
        node*   parent;
        int bf;
        int height;
    };
    template<class T,class Compare, class Alloc = std::allocator<T> >
    class BST
    {
        public:
        typedef T value_type;
        typedef Node<value_type> node;
        typedef Compare key_compare;
        
        typedef std::allocator<node>    Alloc2;
        
        node*   node_new(value_type Data){
            node* nd = myAlloc2.allocate(1);
            myAlloc1.construct(&nd->data, Data);
            nd->left = 0;
            nd->right = 0;
            nd->parent = 0;
            nd->height = 1;
            nd->bf = 0;
            return nd;
        }
        
        BST(void):root(0), cmp(){
            
        }
        ~BST(void){
            tree_free(root);
        }

        size_t      max(size_t h1, size_t h2){
            return (h1 < h2) ? h2 : h1;
        }

        size_t      height(node* node){
            if (node == NULL)
                return 0;
            return node->height;
        }

        int            BF(node *x){
            return height(x->right) - height(x->left);
        }

        void       insert(node** Root, node* nd){
            node* y = 0;
            node *x = (*Root);
            
            while (x != 0){
                y = x;
                if (cmp(nd->data.first, x->data.first))
                    x = x->left;
                else
                    x = x->right;
            }
            nd->parent = y;
            if (y == NULL)
                (*Root) = nd;
            else if (cmp(nd->data.first , y->data.first))
                y->left = nd;
            else
                y->right = nd;

            node* toto = y;
            while (toto != NULL){
                toto->height = max(height(toto->right), height(toto->left)) + 1;
                toto->bf = BF(toto);
                std::cout << "ww" << toto->data << std::endl;
                if (Rebalance(toto))
                    toto = toto->parent;
                // check if the balance is broken
                toto = toto->parent;
            }
            
            
        }

        node* rotate_left(node* x, node* z)
        {
            // std::cout << "rotate left [" << (*x)->data << " | " << (*z)->data << "]" << std::endl;
            
        
            // std::cout << "kk" << std::endl;
            node* t23 = x->parent;
			node* y = z->left;
			x->right = y;
			if (y != NULL)
				y->parent = x;
			z->left = x;
			x->parent = z;
			z->parent = t23;
			if (t23 == NULL)
				this->root = z;
			if (t23  && t23->right == x)
				t23->right = z;
			if (t23 && t23->left == x)
				t23->left = z;

			x->height = max(height(x->right), height(x->left)) + 1;
			z->height = max(height(z->right), height(z->left)) + 1;
			x->bf = BF(x);
			z->bf = BF(x);
			return z;
        }
         node* rotate_right(node* x, node*z)
        {
           
            std::cout << "kk" << std::endl;
            
            node* t23 = x->parent;
			node* t24 = z->right;
			x->left = t24;
			if (t24 != NULL)
				t24->parent = x;
			z->right = x;
			x->parent = z;
			z->parent = t23;
			if (t23 == NULL)
				this->root = z;
			if (t23 && t23->right == x)
				t23->right = z;
			if (t23 && t23->left == x)
				t23->left = z;
                
                
			x->height = max(height(x->right), height(x->left)) + 1;
			z->height = max(height(z->right), height(z->left)) + 1;

			x->bf = BF(x);
			z->bf = BF(x);
            
            return z;
        }
        
        int Rebalance(node* nd)
        {
            std::cout << " rebalance " << nd->bf << std::endl;
            if (nd->bf == 2 && nd->right->bf > 0){
                rotate_left(nd, (nd->right));
                return 1;
            }
                
            else if (nd->bf == -2 && nd->left->bf <=0){
                rotate_right(nd, nd->left);
                return 1;
            }
                
            else if (nd->bf == 2 && nd->right->bf <=0)
                {
                    rotate_right(nd->right, nd->right->left);
                    rotate_left(nd, (nd->right));
                    return 1;
                    }
                
            else if (nd->bf == -2 && nd->left->bf >=0)
            {
                rotate_left((nd->left), (nd->left->right));
                rotate_right(nd, nd->left);
                return 1;
            }
            return 0;
                         
        }

        void    tree_free(node* root)
        {
            if (root == 0)
                return ;
            tree_free(root->left);
            tree_free(root->right);
            myAlloc2.deallocate(root, 1);
            root = 0;
        }
        node* tree_min(node* x)
        {
            while(x->left != 0)
                x = x->left;
            return x;    
        }
        node* tree_successor(node* x)
        {
            node* y;
            if(x->right != 0)
                return (tree_min(x->right));
            y = x->parent;
            while (y != 0 && x == y->right)
            {
                x = y;
                y = y->parent;
            }
            return y;  
                
        }
        void shift(node **Root,node* nd1, node* nd2)
        {
            if (nd1->parent == 0)
                *(Root) = nd2;
            else if (nd1 == nd1->parent->left)
                nd1->parent->left = nd2;
            else
                nd1->parent->right = nd2;    
              
            if (nd2 == 0)
                nd2->parent = nd1->parent;
            myAlloc2.deallocate(nd1,1);
            nd1 =0;
        }
        node* tree_search(node* x, value_type key)
        {
            if (x == 0 || key.first == x->data.first)
                return x;
            if (cmp(key.first , x->data.first))
                return (tree_search(x->left , key));
            else
                return (tree_search(x->right, key));        
        }

        
        void tree_delete(node **Root, node* nd)
        {
            node* y;
            if(nd->left == 0)
                shift(Root, nd, nd->right);
            else if (nd->right == 0)
                shift(Root, nd,nd->left);
            else
                {
                    y = tree_successor(nd);
                    if (y->parent != nd)
                        {
                            shift(Root,y,y->right);
                            y->right = nd->right;
                            y->right->parent = y;
                        }
                    shift(Root, nd, y);
                    y->left = nd->left;
                    y->left->parent = y;    
                }        
        }
        void	tree_debug(const std::string &prefix,
            const node* node, bool isLeft){
        if(node != NULL)
        {
            std::cout << prefix;
            std::cout << (isLeft?"├──" : "└──");
            std::cout << "|" << node->data << "|" << node->bf << std::endl;

            tree_debug(prefix+(isLeft?"│   "
                        : "    "),
                    node->left, true);
            tree_debug(prefix+(isLeft?"│   "
                        : "    "),
                    node->right, false);
            }
        }
        void	tree_debug(const node* root){
            std::cout << std::endl;
            tree_debug("$", root, false);
        }
        public:
            node    *root;
            Alloc   myAlloc1;
            Alloc2  myAlloc2;
            // comparison object
            key_compare cmp;
    };
   
    
}