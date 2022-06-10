#pragma once
#include "bst.hpp"
#include <iterator>




namespace ft
{
	template <class T, class Compare>
		class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>{
		public:
			
			typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef T value_type;
			typedef ptrdiff_t	difference_type;
			typedef T*		pointer;
			typedef T&		reference;
			typedef node<T>	Node;

		
		bidirectional_iterator(void) : _ptr(0), comp(){};
		
		bidirectional_iterator(bidirectional_iterator const &cp){
			*this = cp;
		}
		
		bidirectional_iterator(pointer ptr) :
			_ptr(ptr), comp(){}
		
		bidirectional_iterator(pointer ptr, node<T> * const tree, node<T>* currentnode) :
			_ptr(ptr), _myTree(tree),_currentNode(currentnode), comp(){}
		
		bidirectional_iterator&	operator=(bidirectional_iterator const &rhs)
        {
			if (this != &rhs)
            {
		
				this->_ptr = rhs._ptr;
				this->_myTree = rhs._myTree;
				this->_currentNode = rhs._currentNode;
			}
			return *this;
		}
		
		~bidirectional_iterator(void){}
		
		pointer	operator ->(void) const{return _ptr;}
		reference operator *(void) const{return *_ptr;}
		
		
		bidirectional_iterator	operator++(int){
			bidirectional_iterator tmp = *this;
			Node* successor = _successor(
					_currentNode);
			if (successor != NULL){
				_ptr = &(successor->data);			
				_currentNode = successor;
			}
			else{
				_ptr = 0x0;
				_currentNode = 0x0;
			}
			return tmp;
		}
		bidirectional_iterator	operator++(void){
			Node* successor = _successor(
						_currentNode);
			if (successor != NULL){
				_currentNode = successor;
				_ptr = &(successor->data);			
			}
			else{
				_ptr = 0x0;
				_currentNode = 0x0;
			}
			return *this;
		}
	
		bidirectional_iterator operator--(int){
			bidirectional_iterator tmp = *this;


			if (_ptr == 0x0){
				Node* t = _max(_myTree);
				_ptr = &(t->data);
				_currentNode = t;
				return tmp;
			}
			Node* predecessor = _predecessor(
					_currentNode);
			if (predecessor != NULL){
				_ptr = &(predecessor->data);
				_currentNode = predecessor;
			}
			else{
				_ptr = 0x0;
				_currentNode = 0x0;
			}
			return tmp;
		}
		bidirectional_iterator operator--(void){
			if (_ptr == 0x0){
				Node* t = _max(_myTree);
				_ptr = &(t->data);
				_currentNode = t;
				return *this;
			}
			Node* predecessor = _predecessor(
					_currentNode);
			if (predecessor != NULL){
				_ptr = &(predecessor->data);
				_currentNode = predecessor;
			}
			else{
				_ptr = 0x0;
				_currentNode = 0x0;
			}
			return *this;
		}
		
		Node	*_max(Node* x){
			while (x->right != NULL)
				x = x->right;
			return x;
		}
		
		Node	*_min(Node* x) const{
			while (x->left != NULL)
				x = x->left;
			return x;
		}
		
		Node*	_successor(Node* x){
			if (x->right != NULL)
				return _min(x->right);
			Node* y = x->parent;
			while (y != NULL && x == y->right){
				x = y;
				y = y->parent;
			}
			return y;
		}
		
		Node*	_predecessor(Node* x){
			if (x->left != NULL)
				return _max(x->left);
			Node* y = x->parent;
			while (y != NULL && x == y->left){
				x = y;
				y = y->parent;
			}
			return y;
		}
		Node*	_search(Node* x, value_type key) const{
			if (x == NULL || key.first == x->data.first)
				return x;
			if (comp(key.first, x->data.first))
				return _search(x->left , key);
			else
				return _search(x->right, key);
		}
		// Conversion operator
		operator bidirectional_iterator<const T, Compare>() const{
			return bidirectional_iterator<const T, Compare>(_ptr, reinterpret_cast<node<const T>*>(_myTree), reinterpret_cast<node<const T>*>(_currentNode));
		}

		pointer get_ptr(void){ return _ptr;}
		Node*	get_node(void) {return _currentNode;}
		void	debugg(void){std::cout << _ptr << std::endl;std::cout << _currentNode << std::endl;}
		private:
			pointer	_ptr;
			Node*	_myTree;
			Node*	_currentNode;
			Compare comp;
		};
	
	// comparison
	template <class T1, class T2, class Compare>
		bool	operator==(bidirectional_iterator<T1, Compare> lhs,
				bidirectional_iterator<T2, Compare> rhs){
			return lhs.get_ptr() == rhs.get_ptr();
		}
	template <class T1, class T2, class Compare>
		bool	operator!=(bidirectional_iterator<T1, Compare> lhs,
				bidirectional_iterator<T2, Compare> rhs){
			return lhs.get_ptr() != rhs.get_ptr();
		}

}

