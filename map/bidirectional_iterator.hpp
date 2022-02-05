

#include "bst.hpp"
namespace ft
{
template <class T, class Compare>
		class bidirectional_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
        {
        public:
            typedef typename std::bidirectional_iterator_tag	iterator_category;
			typedef T value_type;
			typedef ptrdiff_t	difference_type;
			typedef T*		pointer;
			typedef node<T>	node;
			typedef T&		reference;



        bidirectional_iterator(void) : _ptr(0), comp()
        {
        }
		
		bidirectional_iterator(bidirectional_iterator const &cp)
        {
			*this = cp;
        }

        private:
        Compare comp;
        pointer ptr;    

        };
}