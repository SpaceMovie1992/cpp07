#include "Array.hpp"

int main()
{
	std::cout << "== Empty Array Test ==" << std::endl;
	Array<int> empty;
	std::cout << "Size: " << empty.size() << std::endl;

	try
	{
		empty[0] = 42;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n== Int Array Initialization ==" << std::endl;
	Array<int> numbers(5);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = i * 10;

	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	std::cout << "\n== Copy Constructor Test ==" << std::endl;
	Array<int> copy(numbers);
	numbers[0] = 999;
	std::cout << "copy[0] = " << copy[0] << " (should not be 999)" << std::endl;

	std::cout << "\n== Assignment Operator Test ==" << std::endl;
	Array<int> assigned;
	assigned = numbers;
	numbers[1] = 888;
	std::cout << "assigned[1] = " << assigned[1] << " (should not be 888)" << std::endl;

	std::cout << "\n== Out of Bounds Access ==" << std::endl;
	try
	{
		std::cout << numbers[42] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n== Array of Strings ==" << std::endl;
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "array";
	words[2] = "template";

	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;

	return 0;
}
