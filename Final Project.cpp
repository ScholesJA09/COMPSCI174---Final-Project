#include <iostream>
#include <string>
#include <iomanip>
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
	//Items to purchase
	item items[10] = {
		item("Apple", 1.25, 10),
		item("Banana", 0.80, 20),
		item("Cereal", 4.00, 8),
		item("Milk", 2.30, 12),
		item("Eggs", 3.00, 16),
		item("Bread", 3.30, 24),
		item("Peanut Butter", 5.80, 14),
		item("Soda", 9.00, 8),
		item("Cookies", 4.80, 10),
		item("Ice Cream", 4.60, 8),
	};

	//Cart Declaration
	const int cart_max = 10;
	item cart[cart_max];
	int current_cart_qty = 0;

	std::string temp;
	int num = 0;
	while (!(num == 5))
	{
		//Options
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
			//Adding item to cart
			items[0].add_item(items, cart, current_cart_qty, cart_max);
		}
		else if (num == 2)
		{
			//Viewing items in cart
			std::cout << "\n--- Items in Cart ---" << std::endl;
			for (int i = 0; i < current_cart_qty; i++)
			{
				cart[i].print_cart();
			}
			if (current_cart_qty == 0)
			{
				std::cout << "Cart is empty." << std::endl;
			}
			std::cout << "------------------------\n" << std::endl;
		}
		else if (num == 3)
		{
			//Viewing items for purchase
			std::cout << "\n--- Available Items ---" << std::endl;
			for (int i = 0; i < 10; i++)
			{
				std::cout << "[" << (i + 1) << "] ";
				items[i].print_item();
			}
			std::cout << "------------------------\n" << std::endl;
		}
		else if (num == 4)
		{
			//Checking out
			if (current_cart_qty == 0)
			{
				std::cout << "\nCart is empty. Nothing to check out.\n" << std::endl;
			}
			else
			{
				double total_price = 0.0;
				std::cout << "\n--- Checking Out --- " << std::endl;

				// FIX: apply fixed + setprecision so all dollar amounts print as X.XX
				std::cout << std::fixed << std::setprecision(2);

				for (int i = 0; i < current_cart_qty; i++)
				{
					std::cout << cart[i].get_name() << " - $" << cart[i].get_price() << std::endl;
					total_price += cart[i].get_price();
				}

				std::cout << "--------------------" << std::endl;
				std::cout << "TOTAL: $" << total_price << std::endl;
				std::cout << "Thank you for your purchase!\n" << std::endl;

				current_cart_qty = 0;
			}
		}
	}
	//User Inputs 5
	std::cout << "\nCome back soon!" << std::endl;
	return 0;
}
