// #include "map/map.hpp"
// #include "map/bst.hpp"
// #include "map/pair.hpp"

// void    foo(void)
// {
    // ft::BST<ft::pair<int, int>, std::less<int> >    myfirstTree;
    // // int arr[] = {3,2,4};

    // for (int i = 0; i < 10; i++)
    //     myfirstTree.insert(&(myfirstTree.root), myfirstTree.node_new(ft::make_pair(i, 42)));
    // // myfirstTree.insert(&(myfirstTree.root), myfirstTree.node_new(ft::make_pair(5, 42)));
    // // myfirstTree.insert(&(myfirstTree.root), myfirstTree.node_new(ft::make_pair(8, 42)));

    

    // myfirstTree.tree_delete(&(myfirstTree.root),myfirstTree.tree_search((myfirstTree.root),ft::make_pair(0, 42)));
    // myfirstTree.tree_delete(&(myfirstTree.root),myfirstTree.tree_search((myfirstTree.root),ft::make_pair(2, 42)));

    // std::cout << "tt" << std::endl;
    // // std::cout << myfirstTree.root->parent->right->data << std::endl;

    // myfirstTree.tree_debug(myfirstTree.root);

// }


// int     main()
// {
//     // foo();
//     // system("leaks a.out");
//     ft::Map<int, std::string> d;
//  ft::Map<int,std::string>::iterator it;

//     for (size_t i = 0; i < 10; i++)
//     {
//      d.insert(ft::make_pair(i,std::to_string(i)));
//     }
    

//     for(ft::Map<int, std::string>::iterator i = d.begin();i != d.end(); ++i)
//         std::cout << i->second << std::endl;

//     // ft::map<int , int>::iterator c = d.begin();
//     // d.erase(c , d.end());

//     // it = d.find((2));
//     // d.erase(it);
//     d.Debug();


//     return 0;
// }
//   ft::Map<int, int> my;
//     ft::pair<int, int> a1 = ft::make_pair<int, int>(1,1);
//     ft::pair<int, int> a2 = ft::make_pair<int, int>(1,1);
    // my.insert(a1);
    // my.insert(a2);
    // ft::Map<int, int>::iterator it1 = my.begin();
    // ft::Map<int, int>::const_iterator it2;


// 	template <class T>
// void    debug(ft::Vector<T> vec1){
//     for (int i=0; i < vec1.size(); i++){
//         std::cout << vec1[i] << " ";
//     }
//     std::cout << std::endl;
// }

// int     main()
// {
//     ft::Vector<int> myvec(20, 42);
//     myvec.insert(myvec.begin()+10, 100, 69);
//     debug<int>(myvec);

//     return 0;
// }

#include "../stack.hpp"       // your stack path.
#include "../vector.hpp" // your Vector path.
#include "../map/pair.hpp"  // path to ft::pair.

#include <vector>
#include <stack>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3 // the ft::Map methods can be slower up to std::map methods * TIME_FAC (MAX 20)


#define TEST_CASE(fn)                                                                                                             \
    cout << GREEN << "\t======================================================================================" << RESET << endl; \
    cout << endl;                                                                                                                 \
    cout << BLUE << "\t   Running " << #fn << " ... \t\t\t\t\t\t" << RESET << std::endl;                                          \
    fn();                                                                                                                         \
    cout << endl;                                                                                                                 \
    cout << GREEN << "\t======================================================================================" << RESET << endl;
using namespace std;

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}

void	testConstructors(void)
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " default constructor "
              << "] --------------------]\t\t\033[0m";
	{
		std::vector<int> myvector (2,200);
		ft::Stack<int,std::vector<int> > s(myvector);
		EQUAL(s.size() == 2);
	}
}

void	testMemberMethods(void)
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " empty method "
              << "] --------------------]\t\t\033[0m";
	{
		ft::Stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		EQUAL(sum == 55);
	}
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size method "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		ft::Stack<int> myints;
		cond = myints.size() == 0;

		for (int i=0; i<5; i++) myints.push(i);
		cond = cond && (myints.size() == 5);

		myints.pop();
		cond = cond && (myints.size() == 4);
		EQUAL(cond);
	}
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " top method "
              << "] --------------------]\t\t\033[0m";
	{
		ft::Stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;
		std::vector<int> vec(10, 50);
		vec.push_back(300);
		ft::Stack<int, std::vector<int> > const c_mystack(vec);

		EQUAL(mystack.top() == 15 && c_mystack.top() == 300);
	}
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " push & pop methods "
              << "] --------------------]\t\t\033[0m";
	{
		int sum(0);
		ft::Stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		EQUAL(sum == 10);
	}
}

void	testRelationalOperators(void)
{
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator== "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack ==  mystack1) == (stack == stack1);
		}
		{
			vec.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack ==  mystack1) == (stack == stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack ==  mystack1) == (stack == stack1);
		}
		EQUAL(cond);
	}
	std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator!= "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack !=  mystack1) == (stack != stack1);
		}
		{
			vec.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack !=  mystack1) == (stack != stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack !=  mystack1) == (stack != stack1);
		}
		EQUAL(cond);
	}
	std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator< "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack < mystack1) == (stack < stack1);
		}
		{
			vec.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack < mystack1) == (stack < stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack < mystack1) == (stack < stack1);
		}
		EQUAL(cond);
	}
    std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator<= "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack <= mystack1) == (stack <= stack1);
		}
		{
			vec.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack <= mystack1) == (stack <= stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack <= mystack1) == (stack <= stack1);
		}
		EQUAL(cond);
	}
	std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator> "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack > mystack1) == (stack > stack1);
		}
		{
			vec.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack > mystack1) == (stack > stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack > mystack1) == (stack > stack1);
		}
		EQUAL(cond);
	}
	std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " operator>= "
              << "] --------------------]\t\t\033[0m";
	{
		bool cond(false);
		std::vector<int>	vec(100, 2);
		std::vector<int>	vec1(100, 2);
		{
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = (mystack >= mystack1) == (stack >= stack1);
		}
		{
			vec.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack >= mystack1) == (stack >= stack1);
		}
		{
			vec.pop_back();
			vec1.push_back(300);
			ft::Stack<int, std::vector<int> > mystack1(vec);
			ft::Stack<int, std::vector<int> > mystack(vec1);
			std::stack<int, std::vector<int> > stack1(vec);
			std::stack<int, std::vector<int> > stack(vec1);
			cond = cond && (mystack >= mystack1) == (stack >= stack1);
		}
		EQUAL(cond);
	}
}


void alarm_handler(int seg)
{
    (void)seg;
    std::cout << "\033[1;33mTLE\033[0m\n";
    kill(getpid(), SIGINT);
}

int main()
{
	std::cout << RED << "________________________________________________________________________________________________________" << std::endl;
    std::cout << RED << "**** The test is taking so much time to test the all cases and the time complexity of each method ****" << std::endl;
    std::cout << RED << "--------------------------------------------------------------------------------------------------------" << RESET << std::endl;
    signal(SIGALRM, alarm_handler);

    std::cout << YELLOW << "Testing Constructors;" << RESET << std::endl;
    TEST_CASE(testConstructors);

    std::cout << YELLOW << "Testing member methods;" << RESET << std::endl;
    TEST_CASE(testMemberMethods);

    std::cout << YELLOW << "Testing relational operators;" << RESET << std::endl;
    TEST_CASE(testRelationalOperators);
	system("leaks a.out");

	return 0;
}