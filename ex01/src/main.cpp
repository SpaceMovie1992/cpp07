#include "iter.hpp"

void add_two(int& x){
	x += 2;	
}

void uppercase(char& c){
	c = toupper(c);
}

template <typename T> void print(const T& x) { std::cout << x << " "; }

int main(void)
{
	int arr_int[] = {1, 7, 2};

	std::cout << "Before modification: " << std::endl;
	iter(arr_int, 3, print);
	std::cout << std::endl;
	
	std::cout << "Adding 2: " << std::endl;
	iter(arr_int, 3, add_two);
	iter(arr_int, 3, print);
	std::cout << std::endl;

	std::cout << "Char array before modification: " << std::endl;
	char arr_char[] = {'a', 'V', '%', 'y', '1', 'b'};
	iter(arr_char, 6, print);
	std::cout << std::endl;

	std::cout << "Making uppercase: " << std::endl;
	iter(arr_char, 6, uppercase);
	iter(arr_char, 6, print);
	std::cout << std::endl;

	return 0;
}
