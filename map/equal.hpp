



namespace ft
{
	template <class InputIterator1, class InputIterator2>
		bool    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
		{
			while (first1 != last1){
				if (*first1 != *first2)
					return false;
				++first1;
				++first2;
			}
			return true;
		}
}

//lexico_compare

namespace ft
{
	template < class InputIterator1, class InputIterator2>
		bool    lexicographical_compare(InputIterator1 first1, InputIterator1 last1
				,InputIterator2 first2, InputIterator2 last2)
		{
			while(first1!=last1){
				if (first2==last2 || *first2<*first1) return false;
				else if (*first1<*first2) return true;
				++first1;
				++first2;
			}
			return (first2!=last2);
		}
}
	
				// insertion avl
				pair<Node*,bool>	insert_ext(Node** Root, Data data){
					// std::cout << "nb of times: " << data << std::endl;
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
					
					if (y != NULL){
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
					pair<Node*,bool>	bobo = insert_ext(Root,data);
					return bobo;
				}

				//insert
				ft::pair<iterator, bool> insert (const value_type& val){
				pair<Node*,bool> toto = _AVL.insert(&_AVL.root, val);
				if (toto.second != false){
					_size++;
					return ft::make_pair<iterator, bool>(iterator(&toto.first->data, _AVL.root, toto.first), true);
				}
				return ft::make_pair<iterator, bool>(iterator(&toto.first->data, _AVL.root, toto.first), false);}