/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:14:16 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/03/01 10:25:20 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <functional>
#include "pair.hpp"

namespace ft
{
	template <class T>
		struct node{
			T data;
			node* right;
			node* left;
			node* parent;
			int		bf;
			size_t  height;
			node (const node & obj)
            {
				data = obj.data;
				left = obj.left;
				right = obj.right;
				parent = obj.parent;
				bf = obj.bf;
				height = obj.height;
				return *this;
			}
			operator node<const T>() const
            {
				return node<const T>();
			}
		};
	template <class U, class Compare, class Alloc = std::allocator<U> >
		class tree{
			public:
				typedef node<U>	Node;
				typedef U	Data;
				typedef Alloc	allocator_type1;
				typedef Compare key_compare;

				typedef typename allocator_type1::template rebind<Node>::other allocator_type2;
			
				tree(const allocator_type1& alloc = allocator_type1())
					:root(0), myAlloc1(alloc), myAlloc2(allocator_type2()), comp()
                    {
					}
				~tree(void)
                {
				}
				tree& operator=(tree const &rhs)
                {
					if (this != &rhs){
						root = rhs.root;
					}
					return *this;
				}
		
				size_t	max(size_t a, size_t b)
                {
					return (a<b ? b : a);
				}

				int		BF(Node* node)
                {
					return height(node->right) - height(node->left);
				}
                
				size_t	height(Node* node)
                {
					if (node == NULL)
						return 0;
					return node->height;
				}
				
                
				Node*	node_new(Data Data, Node* Parent)
                {
					Node* node = myAlloc2.allocate(1);
					node->left = NULL;
					node->right = NULL;
					node->parent = Parent;
					myAlloc1.construct(&node->data, Data);
					node->bf = 0;
					node->height = 1;
					return node;
				}
				
            
				Node*	tree_search(Node* x, Data key) const{
					if (x == NULL || key.first == x->data.first)
						return x;
					if (comp(key.first, x->data.first))
						return tree_search(x->left , key);
					else
						return tree_search(x->right, key);
				}
				// insertion
				pair<Node*,bool>	insert_ext(Node** Root, Data data)
                {
			
					Node*	y = NULL;
					Node*	x = *Root;
					int ht = 0;
					while (x != NULL){
						y = x;
						if (comp(data.first, x->data.first))
							x = x->left;
						else if (data.first == x->data.first)
							return ft::make_pair(x, false);
						else
							x = x->right;
						ht++;
					}
					Node* z = node_new(data, y);
					if (y == NULL){
						*Root = z;
					}
					else if (comp(z->data.first, y->data.first)){
						y->left = z;
					}
					else{
						y->right = z;
					}
					if (y != NULL)
                    {
						Node *m = y;
						while (m != NULL) {
							m->height = max(height(m->right), height(m->left)) + 1;
							m->bf = BF(m);
							if (rebalance(m))
								m = m->parent;
							m = m->parent;
						}
					}
					return ft::make_pair(z, true);

				}
				pair<Node*,bool>	insert(Node** Root, Data data){
					pair<Node*,bool>	nd = insert_ext(Root,data);
					return nd;
				}


				void tree_delete(Node** T, Node* z)
                {
					if (z == NULL)
						return ;
					tree_delete2(T,z);
				}
				void	tree_delete2(Node** T, Node* z)
                {
					Node* tmp = tree_predecessor(z);
					if (z->left == NULL)
						subtree_shift(T, z, z->right);
					else if (z->right == NULL)
						subtree_shift(T, z, z->left);
					else{
						Node* y = tree_successor(z);
						if (y->parent != z){
							subtree_shift(T, y, y->right);
							y->right = z->right;
							y->right->parent = y;
						}
						subtree_shift(T, z, y);
						y->left = z->left;
						y->left->parent = y;
					}
					myAlloc1.destroy(&z->data);
					myAlloc2.deallocate(z, 1);
					while (tmp){
						tmp->height = max(height(tmp->right),height(tmp->left))+1;
						tmp->bf = height(tmp->right) - height(tmp->left);
						if (rebalance(tmp))
							tmp = tmp->parent;
						tmp = tmp->parent;
					}
				}
                
				void	subtree_shift(Node** T, Node* u, Node* v)
                {
					if (u->parent == NULL)
						*T = v;
					else if (u == u->parent->left)
						u->parent->left = v;
					else
						u->parent->right = v;
					if (v != NULL)
						v->parent = u->parent;
				}
				
				void	tree_free(Node* Root){
					if (Root == NULL)
						return ;
					tree_free(Root->left);
					tree_free(Root->right);
					myAlloc1.destroy(&Root->data);
					myAlloc2.deallocate(Root, 1);
					Root = 0x0;
				}
			
				Node	*tree_max(Node* x)
                {
					while (x->right != NULL)
						x = x->right;
					return x;
				}
				
				Node	*tree_min(Node* x) const
                {
					if (x == NULL)
						return x;
					while (x->left != NULL)
						x = x->left;
					return x;
				}
				
				Node*	tree_successor(Node* x)
                {
					if (x->right != NULL)
						return tree_min(x->right);
					Node* y = x->parent;
					while (y != NULL && x == y->right){
						x = y;
						y = y->parent;
					}
					return y;
				}
				
				Node*	tree_predecessor(Node* x)
                {
					if (x->left != NULL)
						return tree_max(x->left);
					Node* y = x->parent;
					while (y != NULL && x == y->left){
						x = y;
						y = y->parent;
					}
					return y;
				}
				
                
				size_t	tree_height(Node* x){
					if (x == NULL)
						return 0;
					size_t	left_height = tree_height(x->left);
					size_t	right_height = tree_height(x->right);
					if(left_height > right_height)
						return left_height+1;
					else
						return right_height+1;
				}
			
            
				int	rebalance(Node* Root)
                {
					if (Root->bf == 2 && Root->right->bf >= 0){
						rotate_left(Root, Root->right);
						return 1;
					}
					else if (Root->bf == -2 && Root->left->bf <= 0){
						rotate_right(Root, Root->left);
						return 1;
					}
					else if (Root->bf == 2 && Root->right->bf <= 0){
						rotate_right(Root->right, Root->right->left);
						rotate_left(Root, Root->right);
						return 1;
					}
					else if (Root->bf == -2 && Root->left->bf >= 0){
						rotate_left(Root->left, Root->left->right);
						rotate_right(Root, Root->left);
						return 1;
					}
					return 0;
				}

				
				Node*	rotate_left(Node* nd1, Node* nd2)
                {
					Node* ll = nd1->parent;
					Node* y = nd2->left;
					nd1->right = y;
					if (y != NULL)
						y->parent = nd1;
					nd2->left = nd1;
					nd1->parent = nd2;
					nd2->parent = ll;
					if (ll == NULL)
						this->root = nd2;
				
					if (ll  && ll->right == nd1)
						ll->right = nd2;
					if (ll && ll->left == nd1)
						ll->left = nd2;

					nd1->height = max(height(nd1->right), height(nd1->left)) + 1;
					nd2->height = max(height(nd2->right), height(nd2->left)) + 1;
					nd1->bf = BF(nd1);
					nd2->bf = BF(nd1);
					return nd2;
				
				}
				
				Node*	rotate_right(Node* nd1, Node* nd2)
				{
					Node* nd = nd1->parent;
					Node* t23 = nd2->right;
					nd1->left = t23;
					if (t23 != NULL)
						t23->parent = nd1;
					nd2->right = nd1;
					nd1->parent = nd2;
					nd2->parent = nd;
					if (nd == NULL)
						this->root = nd2;
					if (nd && nd->right == nd1)
						nd->right = nd2;
					if (nd && nd->left == nd1)
						nd->left = nd2;
					nd1->height = max(height(nd1->right), height(nd1->left)) + 1;
					nd2->height = max(height(nd2->right), height(nd2->left)) + 1;

					nd1->bf = BF(nd1);
					nd2->bf = BF(nd1);
					
					return nd2;
				}
				
				void	tree_debug(const std::string &prefix,
						const Node* node, bool isLeft){
					if(node != NULL)
					{
						std::cout << prefix;
						std::cout << (isLeft?"├──" : "└──");
						std::cout << "|" << node->data << ":" << node->height << "/" << node->bf << std::endl;

						tree_debug(prefix+(isLeft?"│   "
									: "    "),
								node->left, true);
						tree_debug(prefix+(isLeft?"│   "
									: "    "),
								node->right, false);
					}
				}
				void	tree_debug(const Node* root){
					std::cout << std::endl;
					tree_debug("$", root, false);
				}

				Node*	root;
				allocator_type1 myAlloc1;
				allocator_type2	myAlloc2;
				key_compare	comp;
		};
}

