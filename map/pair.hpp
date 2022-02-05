/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:38:55 by zzarrafa          #+#    #+#             */
/*   Updated: 2022/02/05 13:08:14 by zineb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#pragma once

namespace ft
{
  template <class T1, class T2>
  struct pair
  {
  public:
    typedef T1 first_type;
    typedef T2 second_type;

    first_type first;
    second_type second;
    pair() : first(), second()
    {
    }
    template <class U, class V>
    pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
    {
    }
    pair(const first_type &x, const second_type &y) : first(x), second(y)
    {
    }
    pair &operator=(const pair &rh)
    {
      this->first = rh.first;
      this->second = rh.second;
      return (*this);
    }
  };
  template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
      return ( pair<T1,T2>(x,y) );
    }
  template<class T1, class T2>
    std::ostream &operator << (std::ostream& o, const pair<T1, T2> &p){
      o << "(" << p.first << "," << p.second << ")";
      return o;
    }
  
}
// bidirectional_iterator(void) : _ptr(0), comp(){};
// 		// copy constructor
// 		bidirectional_iterator(bidirectional_iterator const &obj){
// 			*this = obj;
// 		}
// 		// parametric constructor takes a pointer
// 		bidirectional_iterator(pointer ptr) :
// 			_ptr(ptr), comp(){}
// 		// parametric constructor takes both a pointer and a root pointer of tree
// 		bidirectional_iterator(pointer ptr, node<T> * const tree, node<T>* currentnode) :
// 			_ptr(ptr), _myTree(tree),_currentNode(currentnode), comp(){}
// 		// assignement overload
// 		bidirectional_iterator&	operator=(bidirectional_iterator const
// 				&rhs){
// 			if (this != &rhs){
// 				// shallow copy, imma test later.
// 				this->_ptr = rhs._ptr;
// 				this->_myTree = rhs._myTree;
// 				this->_currentNode = rhs._currentNode;
// 			}
// 			return *this;
// 		}
// 		// destructor
// 		~bidirectional_iterator(void){}
// 		// rvalue dereference operators * and ->
// 		pointer	operator ->(void) const{return _ptr;}
// 		reference operator *(void) const{return *_ptr;}
		
// 		// increment
// 		bidirectional_iterator	operator++(int){
// 			bidirectional_iterator tmp = *this;
// 			Node* successor = _successor(
// 					_currentNode);
// 			if (successor != NULL){
// 				_ptr = &(successor->data);			
// 				_currentNode = successor;
// 			}
// 			else{
// 				_ptr = 0x0;
// 				_currentNode = 0x0;
// 			}
// 			return tmp;
// 		}
// 		bidirectional_iterator	operator++(void){
// 			Node* successor = _successor(
// 						_currentNode);
// 			if (successor != NULL){
// 				_currentNode = successor;
// 				_ptr = &(successor->data);			
// 			}
// 			else{
// 				_ptr = 0x0;
// 				_currentNode = 0x0;
// 			}
// 			return *this;
// 		}
// 		// decrement
// 		bidirectional_iterator operator--(int){
// 			bidirectional_iterator tmp = *this;
// //			std::cerr << "post decrement bidirectional iterator"
// //				<< std::endl;

// 			if (_ptr == 0x0){
// 				Node* t = _max(_myTree);
// 				_ptr = &(t->data);
// 				_currentNode = t;
// 				return tmp;
// 			}
// 			Node* predecessor = _predecessor(
// 					_currentNode);
// 			if (predecessor != NULL){
// 				_ptr = &(predecessor->data);
// 				_currentNode = predecessor;
// 			}
// 			else{
// 				_ptr = 0x0;
// 				_currentNode = 0x0;
// 			}
// 			return tmp;
// 		}
// 		bidirectional_iterator operator--(void){
// 			if (_ptr == 0x0){
// 				Node* t = _max(_myTree);
// 				_ptr = &(t->data);
// 				_currentNode = t;
// 				return *this;
// 			}
// 			Node* predecessor = _predecessor(
// 					_currentNode);
// 			if (predecessor != NULL){
// 				_ptr = &(predecessor->data);
// 				_currentNode = predecessor;
// 			}
// 			else{
// 				_ptr = 0x0;
// 				_currentNode = 0x0;
// 			}
// 			return *this;
// 		}
// 		// tree maximum
// 		Node	*_max(Node* x){
// 			while (x->right != NULL)
// 				x = x->right;
// 			return x;
// 		}
// 		// tree minimum
// 		Node	*_min(Node* x) const{
// 			while (x->left != NULL)
// 				x = x->left;
// 			return x;
// 		}
// 		// tree successor
// 		Node*	_successor(Node* x){
// 			if (x->right != NULL)
// 				return _min(x->right);
// 			Node* y = x->parent;
// 			while (y != NULL && x == y->right){
// 				x = y;
// 				y = y->parent;
// 			}
// 			return y;
// 		}
// 		// tree predecessor
// 		Node*	_predecessor(Node* x){
// 			if (x->left != NULL)
// 				return _max(x->left);
// 			Node* y = x->parent;
// 			while (y != NULL && x == y->left){
// 				x = y;
// 				y = y->parent;
// 			}
// 			return y;
// 		}
// 		Node*	_search(Node* x, value_type key) const{
// 			if (x == NULL || key.first == x->data.first)
// 				return x;
// 			if (comp(key.first, x->data.first))
// 				return _search(x->left , key);
// 			else
// 				return _search(x->right, key);
// 		}
// 		// Conversion operator
// 		operator bidirectional_iterator<const T, Compare>() const{
// 			return bidirectional_iterator<const T, Compare>(_ptr, reinterpret_cast<node<const T>*>(_myTree), reinterpret_cast<node<const T>*>(_currentNode));
// 		}

// 		pointer get_ptr(void){ return _ptr;}
// 		Node*	get_node(void) {return _currentNode;}
// 		void	debugg(void){std::cout << _ptr << std::endl;std::cout << _currentNode << std::endl;}
// 		private:
// 			pointer	_ptr;
// 	template <class T1, class T2, class Compare>
// 		bool	operator!=(bidirectional_iterator<T1, Compare> lhs,
// 				bidirectional_iterator<T2, Compare> rhs){
// 			return lhs.get_ptr() != rhs.get_ptr();
// 		}

// }			Node*	_myTree;
// 			Node*	_currentNode;
// 			Compare comp;
// 		};
// 	// Non member overloads
// 	// comparison
// 	template <class T1, class T2, class Compare>
// 		bool	operator==(bidirectional_iterator<T1, Compare> lhs,
// 				bidirectional_iterator<T2, Compare> rhs){
// 			return lhs.get_ptr() == rhs.get_ptr();
// 		}
