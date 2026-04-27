#include <iostream>
#include <string>
#include "item.h"

int check_input(std::string& temp)
{
	try
	{
		int num = std::stoi(temp);
		if (num > 5 || num < 1)
		{
			std::cout << "\nInput must be 1-5.\n" << std::endl;
		}
		return num;
	}
	catch (const std::exception& e)
	{
		std::cout << "\nInput must be a number.\n" << std::endl;
	}
	return 0;
}

int main()
{
	std::string temp;
	int num = 0;
	while (!(num == 5))
	{
		std::cout << "Welcome! Please choose from the following:" << std::endl;
		std::cout << "[1] Add item to cart" << std::endl;
		std::cout << "[2] View items in cart" << std::endl;
		std::cout << "[3] View items for purchase" << std::endl;
		std::cout << "[4] Check out" << std::endl;
		std::cout << "[5] Exit" << std::endl;

		std::getline(std::cin, temp);
		num = check_input(temp);

		if (num == 1)
		{
			//function for adding item to cart
		}
		else if (num == 2)
		{
			//function for viewing items in cart
		}
		else if (num == 3)
		{
			//function for viewing items for purchase
		}
		else if (num == 4)
		{
			//function for checking out
		}
	}
	std::cout << "\nCome back soon!" << std::endl;
	return 0;
}