#pragma once


class ProductItem {
	int id;
	static int sid;
	Product* product;
	int quantity;
public:

	// Constructors

	ProductItem() : id(0), product(NULL), quantity(0) { }
	ProductItem(Product* product, int quantity) : id(++sid), product(product), quantity(quantity) { }

	// Functions

	double TotalPrice(int quantity) { return product->getPrice() * quantity; }

	// Acsessors

	// Setters

	void setId(int id) { this->id = id; }
	void setProduct(Product* product) { this->product = product; }
	void setQuantity(int quantity) { this->quantity = quantity; }

	// Getters

	const int& getId() { return id; }
	const int& getQuantity() { return quantity; }
	Product getProduct() { return *product; }

	// Function Overloading

	friend ostream& operator<<(ostream& print, const ProductItem& other) {
		cout << *(other.product);
		cout << "Quantity : " << other.quantity << endl;

		return print;
	}

};

int ProductItem::sid = 0;