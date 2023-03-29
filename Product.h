#pragma once


class Product {
	int id;
	static int Sid;
	string name;
	double price;
	string color;
public:

	Product() : id(0), name(""), price(0.0), color("") { }
	Product(string name, double price, string color) {
		id = ++Sid;
		this->name = name;
		this->price = price;
		this->color = color;
	}

	// Setters

	void setName(string name) { this->name = name; }
	void setPrice(double price) { this->price = price; }
	void setColor(string color) { this->color = color; }

	// Getters

	int getId() { return id; }
	string getName() { return name; }
	string getColor() { return color; }
	double getPrice() { return price; }

	// Function Overloading

	friend ostream& operator<<(ostream& print, const Product& other) {
		cout << "Id : " << other.id << endl
			<< "Name : " << other.name << endl
			<< "Price : " << other.price << endl
			<< "Color : " << other.color << endl;
		return print;
	}

	friend istream& operator>>(istream& input, Product& other) {
		other.id = ++other.Sid;
		cout << "Please enter product name : ";
		getline(cin, other.name);
		cout << "Please enter product color : ";
		getline(cin, other.color);
		cout << "Please enter the product price : ";
		cin >> other.price;

		return input;
	}
};

int Product::Sid = 0;