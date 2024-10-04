#pragma once
#include <string>

/**
 * Class representing a commodity item with price and tax handling.
 */
class Commodity {
private:
    std::string name;  // Name of the commodity
    int id;  // ID of the commodity
    double price;  // Price without tax

public:
    /**
     * Constructor for initializing a commodity with name, ID, and price.
     * @param name Name of the commodity.
     * @param id ID of the commodity.
     * @param price Price of the commodity without tax.
     */
    Commodity(std::string name, int id, double price);

    /**
     * Gets the name of the commodity.
     * @return The name of the commodity.
     */
    std::string get_name();

    /**
     * Gets the ID of the commodity.
     * @return The ID of the commodity.
     */
    int get_id();

    /**
     * Gets the price of the commodity per unit.
     * @return Price without tax.
     */
    double get_price();

    /**
     * Gets the price for a specific quantity of the commodity.
     * @param quantity Number of units.
     * @return Total price for the quantity without tax.
     */
    double get_price(double quantity);

    /**
     * Sets a new price for the commodity.
     * @param price New price to set.
     */
    void set_price(double price);

    /**
     * Gets the price with sales tax.
     * @return Price including tax.
     */
    double get_price_with_sales_tax();

    /**
     * Gets the price with sales tax for a specific quantity.
     * @param quantity Number of units.
     * @return Price including tax for the quantity.
     */
    double get_price_with_sales_tax(double quantity);
};
