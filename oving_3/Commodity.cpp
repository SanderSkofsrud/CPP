#include "Commodity.h"
#include <iostream>

const double sales_tax_rate = 1.25;  // Global tax rate

Commodity::Commodity(std::string name, int id, double price)
    : name(name), id(id), price(price) {}

/**
 * Gets the name of the commodity.
 */
std::string Commodity::get_name() {
    return this->name;
}

/**
 * Gets the ID of the commodity.
 */
int Commodity::get_id() {
    return this->id;
}

/**
 * Sets a new price for the commodity.
 */
void Commodity::set_price(double price) {
    this->price = price;
}

/**
 * Gets the price of the commodity per unit.
 */
double Commodity::get_price() {
    return this->price;
}

/**
 * Gets the total price for a specific quantity of the commodity.
 */
double Commodity::get_price(double quantity) {
    return this->price * quantity;
}

/**
 * Gets the price with sales tax for a specific quantity.
 */
double Commodity::get_price_with_sales_tax(double quantity) {
    return this->get_price(quantity) * sales_tax_rate;
}

/**
 * Gets the price with sales tax for one unit.
 */
double Commodity::get_price_with_sales_tax() {
    return this->get_price() * sales_tax_rate;
}

/**
 * Main function to test the Commodity class.
 */
int main() {
    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    std::cout << "Product Name: " << commodity.get_name() << ", Product ID: " << commodity.get_id()
              << " Price per unit: " << commodity.get_price() << std::endl;

    std::cout << "Total price for " << quantity << " units without tax: "
              << commodity.get_price(quantity) << std::endl;
    std::cout << "Total price for " << quantity << " units with tax: "
              << commodity.get_price_with_sales_tax(quantity) << std::endl;

    commodity.set_price(79.60);
    std::cout << "New price per unit: " << commodity.get_price() << std::endl;

    std::cout << "Total price for " << quantity << " units without tax: "
              << commodity.get_price(quantity) << std::endl;
    std::cout << "Total price for " << quantity << " units with tax: "
              << commodity.get_price_with_sales_tax(quantity) << std::endl;

    return 0;
}
