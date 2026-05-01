#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "item.h"

item::item()
{
	this->name = "Empty";
	this->price = 0.00;
	this->stock = 0;
}

item::item(const std::string name, double price, int stock)
{
	set_name(name);
	set_price(price);
	set_stock(stock);
}

std::string item::get_name() const
{
	return name;
}

double item::get_price() const
{
	return price;
}

int item::get_stock() const
{
	return stock;
}

void item::set_name(const std::string name)
{
	if (name.empty())
	{
		throw std::invalid_argument("Name cannot be empty.");
	}
	this->name = name;
}

void item::set_price(double price)
{
	if (price < 0.00)
	{
		throw std::invalid_argument("Price cannot be less than 0.");
	}
	this->price = price;
}

void item::set_stock(int stock)
{
	if (stock < 0)
	{
		throw std::invalid_argument("Stock cannot be less than 0.");
	}
	this->stock = stock;
}

void item::print_item() const
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Item: " << get_name() << " $" << get_price() << " Stock: " << get_stock() << std::endl;
}

void item::print_cart() const
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << get_name() << " - $" << get_price() << std::endl;
}

void item::add_item(item items[], item cart[], int& cart_amount, int cart_size)
{
	std::string input;
	bool adding = true;

	while (adding)
	{
		std::cout << "\nEnter the item number (1-10) to add to cart, or '0' to finish." << std::endl;
		std::getline(std::cin, input);

		try
		{
			int choice = std::stoi(input);

			if (choice == 0)
			{
				std::cout << "Finished Shopping.\n" << std::endl;
				adding = false;
			}
			else
			{
				int index = choice - 1;

				if (index >= 0 && index < 10)
				{
					if (cart_amount < cart_size)
					{
						if (items[index].get_stock() > 0)
						{
							items[index].set_stock(items[index].get_stock() - 1);
							cart[cart_amount] = items[index];
							cart_amount++;

							std::cout << "Added " << items[index].get_name() << " to cart. (Remaining Stock: "
								<< items[index].get_stock() << ")" << std::endl;
						}
						else
						{
							std::cout << "Out of stock! Please choose another item." << std::endl;
						}
					}
					else
					{
						std::cout << "Your cart is full. Cannot add any more items." << std::endl;
						adding = false;
					}
				}
				else
				{
					std::cout << "Invalid choice. Please select 1-10." << std::endl;
				}
			}
		}
		catch (std::exception& e)
		{
			std::cout << "Please enter a valid number." << std::endl;
		}
	}
}

// Stretch #2 - Remove an item from the cart by number and restore its stock
void item::remove_item(item items[], item cart[], int& cart_amount)
{
	if (cart_amount == 0)
	{
		std::cout << "\nCart is empty. Nothing to remove.\n" << std::endl;
		return;
	}

	std::cout << "\n--- Remove an Item ---" << std::endl;
	std::cout << std::fixed << std::setprecision(2);
	for (int i = 0; i < cart_amount; i++)
	{
		std::cout << "[" << (i + 1) << "] " << cart[i].get_name() << " - $" << cart[i].get_price() << std::endl;
	}
	std::cout << "Enter the number of the item to remove, or '0' to cancel." << std::endl;

	std::string input;
	std::getline(std::cin, input);

	try
	{
		int choice = std::stoi(input);

		if (choice == 0)
		{
			std::cout << "Cancelled.\n" << std::endl;
			return;
		}

		int index = choice - 1;

		if (index >= 0 && index < cart_amount)
		{
			std::string removed_name = cart[index].get_name();

			// Restore stock to the matching item in the store inventory
			for (int i = 0; i < 10; i++)
			{
				if (items[i].get_name() == removed_name)
				{
					items[i].set_stock(items[i].get_stock() + 1);
					break;
				}
			}

			// Shift remaining cart items left to fill the gap
			for (int i = index; i < cart_amount - 1; i++)
			{
				cart[i] = cart[i + 1];
			}
			cart_amount--;

			std::cout << removed_name << " removed from cart.\n" << std::endl;
		}
		else
		{
			std::cout << "Invalid choice.\n" << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Please enter a valid number.\n" << std::endl;
	}
}

// Stretch #3 - Sort cart from most to least expensive using bubble sort
void item::sort_cart(item cart[], int cart_amount)
{
	if (cart_amount == 0)
	{
		std::cout << "\nCart is empty. Nothing to sort.\n" << std::endl;
		return;
	}

	for (int i = 0; i < cart_amount - 1; i++)
	{
		for (int j = 0; j < cart_amount - i - 1; j++)
		{
			if (cart[j].get_price() < cart[j + 1].get_price())
			{
				item temp = cart[j];
				cart[j] = cart[j + 1];
				cart[j + 1] = temp;
			}
		}
	}

	std::cout << "\nCart sorted from most to least expensive.\n" << std::endl;
}
