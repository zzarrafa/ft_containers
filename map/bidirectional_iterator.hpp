

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
        bidirectional_iterator&	operator=(bidirectional_iterator const  &rhs)
        {

        }
        bidirectional_iterator	operator++(int){}
        bidirectional_iterator	operator++(){}
        bidirectional_iterator	operator--(int){}
        bidirectional_iterator	operator++(){}
        //conversion
        operator bidirectional_iterator<const T, Compare>() const{}


        //comparaison

        template <class T1, class T2, class Compare>
		bool	operator==(bidirectional_iterator<T1, Compare> lhs, bidirectional_iterator<T2, Compare> rhs){
			return lhs.ptr == rhs.ptr;
		}
	template <class T1, class T2, class Compare>
		bool	operator!=(bidirectional_iterator<T1, Compare> lhs, bidirectional_iterator<T2, Compare> rhs){
			return lhs.ptr != rhs.ptr;
		}

        private:
        Compare comp;
        pointer ptr;    

        };
}