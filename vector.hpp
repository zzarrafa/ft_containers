/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zineb <zineb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 00:13:21 by zineb             #+#    #+#             */
/*   Updated: 2021/08/13 22:02:02 by zineb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



template < class T, class Alloc = allocator<T>>
 
class vector
{
private:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef allocator_type::reference reference ;
    typedef allocator_type::const_reference const_reference	;
    typedef pointer	allocator_type::pointer;
   typedef	allocator_type::const_pointer const_pointer;
public: 
    vector(/* args */);
    ~vector();
    vector(const vector &cp);
    vector & operator=(const vector &rhs);
    void get_allocator();
    
};

vector::vector(/* args */)
{
}

vector::~vector()
{
}
