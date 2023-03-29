#pragma once


class Order {
	ProductItem* productItem;
	const int customerId;
	const int amount;
	string datetime;
public:

	Order() : productItem(NULL), customerId(0), datetime(__TIME__), amount(0) { }
	Order(ProductItem* productItem, const int customerId, string datetime, const int amount) : customerId(customerId), amount(amount) {
		this->productItem = productItem;
		this->datetime = datetime;
	}

	// Acsessors

	// Setters

	void setProductItem(ProductItem productItem) { this->productItem = new ProductItem(productItem); }
	void setCustomerDate(string datetime) { this->datetime = datetime; }

	// Getters

	const ProductItem* getProductItem() { return productItem; }
	const int getCustomerId() { return customerId; }
	const string getDateTime() { return datetime; }

	// Function Overloading

	friend ostream& operator<<(ostream& print, const Order& other) {
		cout << "Product Info\n";
		cout << *other.productItem;
		cout << "Id : " << other.customerId << endl;
		cout << "Amount : " << other.amount << endl;
		cout << "Date Time : " << other.datetime << endl;
		cout << "Total Price : " << other.productItem->TotalPrice(other.amount) << endl;

		return print;
	}


};