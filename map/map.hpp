/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzarrafa <zzarrafa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:05:35 by zineb             #+#    #+#             */
/*   Updated: 2022/03/01 10:26:08 by zzarrafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <functional>
#include "pair.hpp"
#include "bst.hpp"
#include "../reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "equal.hpp"
#include <vector>
#include "lexico_compare.hpp"


namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>,
		 class Alloc = std::allocator<ft::pair<const Key, T> > >
		class Map{
		public:


			typedef Key			key_type;
			typedef T			mapped_type;
			typedef ft::pair<const key_type,mapped_type> value_type;
			typedef Compare			key_compare;
			typedef Alloc			allocator_type;
			typedef value_type&		reference;
			typedef const value_type&	const_reference;
			typedef value_type*		pointer;
			typedef const value_type*	const_pointer;
			typedef bidirectional_iterator<value_type, key_compare> iterator;
			typedef bidirectional_iterator<const value_type, key_compare> const_iterator;
			typedef ptrdiff_t		difference_type;
			typedef size_t			size_type;
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator>		reverse_iterator;

			typedef node<value_type>	Node;
			class value_compare : public std::binary_function<value_type, value_type, bool>{
				friend class map;
				public:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
				public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			};
     // empty
			explicit Map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0){
					(void)comp;

			}
			// range
			template <class InputIterator>
				Map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) : _allocator(alloc), _size(0){
							while (first != last)
              {
								this->insert(*first++);
							}
							(void)comp;
						}
			//  copy 
				Map (const Map& x)
        {
					*this = x;
				}


		
			~Map(void)
      {
				_tree.tree_free(_tree.root);
			}

	
			Map& operator=(Map const &obj)
      {
				this->clear();
				this->insert(obj.begin(),obj.end());
				this->_allocator = obj._allocator;
				return *this;
			}

		// iterators
			iterator	begin(void) 
      {
				Node* curr = _tree.tree_min(_tree.root);
				return iterator(&(curr->data), _tree.root, curr);
			}
      
			const_iterator	begin(void) const 
      {
				Node* curr = _tree.tree_min(_tree.root);
				return const_iterator(&(curr->data), reinterpret_cast<node<const value_type>*>(_tree.root), reinterpret_cast<node<const value_type>*>(curr));
			}

			iterator	end(void) {
				return iterator(0x0, _tree.root, 0x0);
			}
      
			const_iterator	end(void) const
      {
				return const_iterator(0x0, reinterpret_cast<node<const value_type>*>(_tree.root), 0x0);
			}
      
			reverse_iterator	rbegin(void)
      {
				return reverse_iterator(end());
			}
      
			const_reverse_iterator	rbegin(void) const
      {
				return const_reverse_iterator(end());
			}
      
			reverse_iterator	rend(void)
      {
				return reverse_iterator(begin());
			}
			const_reverse_iterator	rend(void) const
      {
				return const_reverse_iterator(begin());
			}

		
			bool	empty(void) const
      {
        return _size == 0;
      }
			size_type	size(void) const
      {
         return _size;
      }
			size_type	max_size(void) const
      {
         return _allocator.max_size();
      }

	
			mapped_type&	operator[] (const key_type& val)
      {
				 return (*((this->insert(ft::make_pair(val,mapped_type()))).first)).second ;
			}

	
			ft::pair<iterator, bool> insert (const value_type& val)
      {
				pair<Node*,bool> toto = _tree.insert(&_tree.root, val);
				if (toto.second != false){
					_size++;
					return ft::make_pair<iterator, bool>(iterator(&toto.first->data, _tree.root, toto.first), true);
				}
				return ft::make_pair<iterator, bool>(iterator(&toto.first->data, _tree.root, toto.first), false);
			}
      
		
			iterator	insert (iterator position, const value_type& val)
      {
				(void)position;
				ft::pair<iterator, bool> ret = insert(val);
				return ret.first;
			}
			
      
			template <class InputIterator>
				void	insert (InputIterator first, InputIterator last)
        {
					while (first != last){
						insert(*first);
						first++;
					}
				}
	
  
			void	erase(iterator position)
      {
				if (position.get_ptr() == 0x0)
					return ;
				_tree.tree_delete(
						&_tree.root,
						position.get_node()
						);
				_size--;
			}
			
			size_type erase (const key_type& k)
      {
				Node* nd = _tree.tree_search(
						_tree.root,
						ft::make_pair(k, mapped_type()));
				if (nd == 0)
					return 0;
				_tree.tree_delete(
					&_tree.root,
					nd
					);
				_size--;
				return 1;
			}
		
			void	erase (iterator first, iterator last)
      {
				std::vector<iterator> vec;
				while (first != last){
					vec.push_back(first++);
				}
				for (size_t i = 0; i<vec.size(); i++){
					erase(vec[i]);
				}
			}

		
			void swap (Map& x){
				std::swap(this->_tree, x._tree);
				std::swap(this->_size, x._size);
			}

		
			void clear()
      {
				_tree.tree_free(_tree.root);
				_tree.root = 0x0;
				_size = 0;
			}

	
			key_compare	key_comp(void) const
      {
				key_compare comp;
				return comp;
			}
			value_compare	value_comp(void) const
      {
				value_compare comp(key_comp());
				return comp;
			}

		
			iterator	find (const key_type& k)
      {
				Node* nd = _tree.tree_search(_tree.root, ft::make_pair(k,mapped_type()));
				return iterator(&(nd->data), _tree.root, nd);
			}
      
			const_iterator	find (const key_type& k) const
      {
				Node* nd = _tree.tree_search(_tree.root, ft::make_pair(k,mapped_type()));
				return const_iterator(&(nd->data), reinterpret_cast<node<const value_type>*>(_tree.root), reinterpret_cast<node<const value_type>*>(nd));
			}
      
			size_type	count (const key_type& k) const
      {
				iterator it = iterator(&(_tree.tree_search(_tree.root, ft::make_pair(k,mapped_type()))->data), _tree.root, _tree.root);
				if (it.get_ptr() != 0x0)
					return 1;
				return 0;
			}
      
			iterator	lower_bound(const key_type& k)
      {
				iterator it = find(k);
				if (it.get_ptr() != 0x0)
					return it;
				Node* succes = _successor(k);
				return iterator(&(succes->data), _tree.root, succes);
			}
      
			const_iterator	lower_bound(const key_type& k) const
      {
				const_iterator cit = find(k);
				if (cit.get_ptr() != 0x0)
					return cit;
				Node* succes = _successor(k);
				return const_iterator(&(succes->data), reinterpret_cast<node<const value_type>*>(_tree.root), reinterpret_cast<node<const value_type>*>(succes));
			}
      
			iterator	upper_bound(const key_type& k)
      {
				Node* succes = _successor(k);
				return iterator(&(succes->data), _tree.root, succes);
			}
      
			const_iterator	upper_bound(const key_type& k) const
      {
				Node* succes = _successor(k);
				return const_iterator(&(succes->data), reinterpret_cast<node<const value_type>*>(_tree.root),reinterpret_cast<node<const value_type>*>(succes));
			}
      
			ft::pair<const_iterator,const_iterator> equal_range(const key_type& k)
				const{
					return ft::make_pair(lower_bound(k), upper_bound(k));
				}
        
			ft::pair<iterator,iterator>	equal_range(const key_type& k){
				return ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));
			}

		
			allocator_type	get_allocator(void) const{
				return _allocator;
			}
		
		void	debug(void){
			_tree.tree_debug(_tree.root);
		}
		private:
			tree<value_type, key_compare>	_tree;
			allocator_type	_allocator;
			size_type	_size;

			Node* _successor( const key_type& key ) const
      {
                Node * successor = nullptr;
				Node * root = this->_tree.root;
				while (root != nullptr) {
					if (key_compare()(key, root->data.first)) {
						successor = root;
						root = root->left;
					}
					else if (!key_compare()(key, root->data.first))
						root = root->right;
				}
				return (successor);
            }
		};

	template < class Key, class T>
		bool	operator == (const Map<Key, T>& lhs, const Map<Key, T>& rhs){
			if (lhs.size() == rhs.size())
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			return false;
		}

	template < class Key, class T>
		bool	operator != (const Map<Key, T>& lhs, const Map<Key, T>& rhs){
			if (lhs.size() == rhs.size())
				return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			return false;
		}

	template < class Key, class T>
		bool	operator < (const Map<Key, T>& lhs, const Map<Key, T>& rhs){
			return ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end());
		}
	template < class Key, class T>
		bool	operator <= (const Map<Key, T>& lhs, const Map<Key, T>& rhs){
			return !ft::lexicographical_compare(rhs.begin(), rhs.end(),
			lhs.begin(), lhs.end());
		}

	template < class Key, class T>
		bool	operator > (const Map<Key, T>& lhs, const Map<Key, T>& rhs){
			return ft::lexicographical_compare(rhs.begin(), rhs.end(),
			lhs.begin(), lhs.end());
		}

	template < class Key, class T>
		bool	operator >= (const Map<Key, T>& lhs, const Map<Key, T>& rhs){
			return !ft::lexicographical_compare(lhs.begin(), lhs.end(),
			rhs.begin(), rhs.end());
		}

}