#include <iostream>
#include <iomanip>
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
		throw std::exception("Name cannot be empty.");
	}
	this->name = name;
}

void item::set_price(double price)
{
	if (price < 0.00)
	{
		throw std::exception("Price cannot be less than 0.");
	}
	this->price = price;
}

void item::set_stock(int stock)
{
	if (stock < 0)
	{
		throw std::exception("Stock cannot be less than 0.");
	}
	this->stock = stock;
}

void item::print_item() const
{
	std::cout << "Item: " << get_name() << " $" << get_price() << " Stock: " << get_stock() << std::endl;
}

void item::print_cart() const
{
	std::cout << get_name() << std::endl;
}

void item::add_item(item items[], item cart[], int& cart_amount, int cart_size)
{
	std::string input;
	bool adding = true;

	while (adding)
	{
		std::cout << "\nEnter the item number(1 - 10) to add to cart, or '0' to finish." << std::endl;
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
							cart[cart_amount] = items[index];
							cart_amount++;

							items[index].set_stock(items[index].get_stock() - 1);

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