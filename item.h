#pragma once
#include <string>

class item
{
private:
	std::string name;
	double price;
	int stock;
public:
	item();
	item(const std::string name, double price, int stock);

	std::string get_name() const;
	double get_price() const;
	int get_stock() const;

	void set_name(const std::string name);
	void set_price(double price);
	void set_stock(int stock);

	void print_item() const;
	void print_cart() const;
	void add_item(item items[], item cart[], int& cart_amount, int cart_size);
	void remove_item(item items[], item cart[], int& cart_amount);  // Stretch #2
	void sort_cart(item cart[], int cart_amount);                   // Stretch #3
};
