#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
#include <vector>

/** method 1
template<typename T>
struct Traits {

    static string name(int i)
    {
        switch(i)
        {
            case 0:
                return (typeid(T) == typeid(Color)) ? 
                "red" : "apple";
            case 1:
                return (typeid(T) == typeid(Color)) ? 
                "green" : "orange";
            case 2:
                return (typeid(T) == typeid(Color)) ? 
                "orange" : "pear";
            default:
                return "unknown";
        }
    }  

};
**/

// method 2 
template<class T>
struct Traits
{
  static vector<string> v;

  static string name(int index)
  {
    return index >= 0 && index <= 2 ? v[index] : "unknown";
  }

  
};
  
template<>
vector<string> Traits<Fruit>::v{"apple", "orange", "pear"};

template<>
vector<string> Traits<Color>::v{"red", "green", "orange"};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
