#include <iostream>
#include <string>
#include <iomanip>
#include "item.h"

int check_input(std::string& temp)
{
	try
	{
		int num = std::stoi(temp);
		if (num > 7 || num < 1)
		{
			std::cout << "\nInput must be 1-7.\n" << std::endl;
		}
		return num;
	}
	catch (const std::exception& e)
	{
		std::cout << "\nInput must be a number.\n" << std::endl;
	}
	return 0;
}

// Stretch #6 - Returns the sales tax rate for the given state abbreviation
// Returns -1 if the state is not recognized
double get_tax_rate(const std::string& state)
{
	if (state == "WI") return 0.05;   // Wisconsin  5.0%
	if (state == "IL") return 0.0625; // Illinois   6.25%
	if (state == "CA") return 0.0725; // California 7.25%
	if (state == "TX") return 0.0625; // Texas      6.25%
	if (state == "NY") return 0.04;   // New York   4.0%
	return -1;
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
	while (!(num == 7))
	{
		//Options
		std::cout << "Welcome! Please choose from the following:" << std::endl;
		std::cout << "[1] Add item to cart" << std::endl;
		std::cout << "[2] View items in cart" << std::endl;
		std::cout << "[3] View items for purchase" << std::endl;
		std::cout << "[4] Check out" << std::endl;
		std::cout << "[5] Remove item from cart" << std::endl;  // Stretch #2
		std::cout << "[6] Sort cart by price" << std::endl;     // Stretch #3
		std::cout << "[7] Exit" << std::endl;

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
				double subtotal = 0.0;
				std::cout << "\n--- Checking Out ---" << std::endl;
				std::cout << std::fixed << std::setprecision(2);

				for (int i = 0; i < current_cart_qty; i++)
				{
					std::cout << cart[i].get_name() << " - $" << cart[i].get_price() << std::endl;
					subtotal += cart[i].get_price();
				}

				// Stretch #6 - Apply sales tax based on state
				std::cout << "--------------------" << std::endl;
				std::cout << "Subtotal: $" << subtotal << std::endl;

				std::string state;
				double tax_rate = -1;
				while (tax_rate == -1)
				{
					std::cout << "Enter your state abbreviation for tax (WI, IL, CA, TX, NY): ";
					std::getline(std::cin, state);

					// Convert to uppercase so "wi" works the same as "WI"
					for (char& c : state) c = toupper(c);

					tax_rate = get_tax_rate(state);
					if (tax_rate == -1)
					{
						std::cout << "State not recognized. Please enter WI, IL, CA, TX, or NY." << std::endl;
					}
				}

				double tax_amount = subtotal * tax_rate;
				double total = subtotal + tax_amount;

				std::cout << "Tax (" << state << " " << (tax_rate * 100) << "%): $" << tax_amount << std::endl;
				std::cout << "TOTAL: $" << total << std::endl;
				std::cout << "Thank you for your purchase!\n" << std::endl;

				current_cart_qty = 0;
			}
		}
		else if (num == 5)
		{
			// Stretch #2 - Remove item from cart
			items[0].remove_item(items, cart, current_cart_qty);
		}
		else if (num == 6)
		{
			// Stretch #3 - Sort cart by price
			items[0].sort_cart(cart, current_cart_qty);
		}
	}
	//User Inputs 7
	std::cout << "\nCome back soon!" << std::endl;
	return 0;
}
