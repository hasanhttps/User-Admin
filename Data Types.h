#pragma once


struct date {
private:
	size_t day;
	size_t month;
	size_t year;
public:

	date() = default;
	date(size_t day, size_t month, size_t year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	// Setters

	void setDay(size_t day) { this->day = day; }
	void setMonth(size_t month) { this->month = month; }
	void setYear(size_t year) { this->year = year; }

	// Getters

	size_t getDay() { return day; }
	size_t getMonth() { return month; }
	size_t getYear() { return year; }

	// Function Overloading

	friend ostream& operator<<(ostream& print, const date& other) {
		cout << other.day << " / " << other.month << " / " << other.year;
		return print;
	}
};


class Person {
protected:
	int id;
	static int Sid;
	string name;
	string surname;
	date dateOfBirth;
public:

	Person() : id(0), name(""), surname(""), dateOfBirth(0, 0, 0) { }
	Person(string name, string surname, date dateOfBirth) {
		id = ++Sid;
		this->name = name;
		this->surname = surname;
		this->dateOfBirth.setDay(dateOfBirth.getDay());
		this->dateOfBirth.setMonth(dateOfBirth.getMonth());
		this->dateOfBirth.setYear(dateOfBirth.getYear());
	}

	// Setters

	void setId(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setSurname(string surname) { this->surname = surname; }
	void setDate(date dateOfBirth) { this->dateOfBirth = dateOfBirth; }

	// Getters

	int getId() { return id; }
	string getName() { return name; }
	string getSurname() { return surname; }
	date getDate() { return dateOfBirth; }


};

class Customer final : public Person{
	string username;
	string password;
	int credit;
public:

	// Constructors

	Customer() : credit(0) {}
	Customer(string name, string surname, string username, string password, date dateOfBirth, int credit):
			Person(name, surname, dateOfBirth) {
		this->credit = credit;
		this->username = username;
		this->password = password;
	}

	// Setters

	void setCredit(int credit) { this->credit = credit; }
	void setUsername(string username) { this->username = username; }
	void setPassword(string password) { this->password = password; }

	// Getters

	int getCredit() { return credit; }

	// Function Overloading

	friend ostream& operator<<(ostream& print, const Customer& other) {
		cout << "Id : " << other.id << endl
			<< "Name : " << other.name << endl
			<< "Surname : " << other.surname << endl
			<< "Username : " << other.username << endl
			<< "Password : " << other.password << endl
			<< "Salary : " << other.credit << endl
			<< "Birth Day : " << other.dateOfBirth << endl;
		return print;
	}

	friend istream& operator>>(istream& input, const Customer& other) {
		string name, surname, username, password;
		size_t day, month, year;
		date date;
		int credit;

		cout << "Please enter the name : ";
		cin >> name;
		cout << "Please enter the surname : ";
		cin >> surname;
		cout << "Please enter the username : ";
		cin >> username;
		cout << "Please enter the password : ";
		while (true) {
			char ascii = _getch();
			if (ascii == '\r') break;
			password.push_back(ascii);
			cout << "*";
		}cout << endl;
		cout << "Please enter the birth day : ";
		cin >> day;
		date.setDay(day);
		cout << "Please enter the birth month : ";
		cin >> month;
		date.setMonth(month);
		cout << "Please enter the birth year : ";
		cin >> year;
		date.setYear(year);
		cout << "Please enter the credit : ";
		cin >> credit;

		other.Customer::Customer(name, surname, username, password, date, credit);

		return input;
	}

	bool operator==(const Customer& other) {
		if (username == other.username && password == other.password) return true;
		return false;
	}
}; 

class Admin final : public Person {
	string username;
	string password;
	int salary;
public:

	Admin() : salary(0) { }
	Admin(string name, string surname, string username, string password, date dateOfBirth, int salary) :
		Person(name, surname, dateOfBirth) {
		this->salary = salary;
		this->username = username;
		this->password = password;
	}

	// Setters

	void setUsername(string username) { this->username = username; }
	void setPassword(string password) { this->password = password; }
	void setSalary(int salary) { this->salary = salary; }

	// Getters

	const int getSalary() { return salary; }
	const string getUsername() { return username; }
	const string getPassword() { return password; }

	// Function Overloading

	friend ostream& operator<<(ostream& print, const Admin& other) {
		cout << "Id : " << other.id << endl
			 << "Name : " << other.name << endl 
			 << "Surname : " << other.surname << endl
			 << "Username : " << other.username << endl
			 << "Password : " << other.password << endl
			 << "Salary : " << other.salary << endl
			 << "Birth Day : " << other.dateOfBirth << endl;
		return print;
	}

	friend istream& operator>>(istream& input, const Admin& other) {
		string name, surname, username, password;
		size_t day, month, year;
		date date;
		int salary;
		cout << "Please enter the name : ";
		cin >> name;
		cout << "Please enter the surname : ";
		cin >> surname;
		cout << "Please enter the username : ";
		cin >> username;
		cout << "Please enter the password : ";
		while (true) {
			char ascii = _getch();
			if (ascii == '\r') break;
			password.push_back(ascii);
			cout << "*";
		}cout << endl;
		cout << "Please enter the birth day : ";
		cin >> day;
		date.setDay(day);
		cout << "Please enter the birth month : ";
		cin >> month;
		date.setMonth(month);
		cout << "Please enter the birth year : ";
		cin >> year;
		date.setYear(year);
		cout << "Please enter the salary : ";
		cin >> salary;

		other.Admin::Admin(name, surname, username, password, date, salary);

		return input;
	}

	bool operator==(const Admin& other) {
		if (username == other.username && password == other.password) return true;
		return false;
	}
};

int Person::Sid = 0;

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

class Database {
	vector<ProductItem*> productItems;
	vector<Order*> orders;
	vector<Customer*> customers;
	vector<Admin*> admins;
public:

	// Constructors

	Database() : productItems(NULL), orders(NULL), customers(NULL), admins(NULL) { }

	// Functions

	void Update();
	void Create() {
		Product* newProduct = new Product();
		int quantity;
		cin >> *newProduct;
		ProductItem* newProductItem = new ProductItem();
		cout << "Please enter the quantity of products : ";
		cin >> quantity;
		newProductItem->setQuantity(quantity);
		newProductItem->setProduct(newProduct);
		setProductItem(newProductItem);
	}
	void Read(int choose) {
		if (choose == 1)
		for (int i = 0; i < productItems.size(); i++) cout << *(productItems[i]) << endl;
		else if (choose == 2)
		for (int i = 0; i < orders.size(); i++) cout << *(orders[i]) << endl;
		else if (choose == 3)
		for (int i = 0; i < customers.size(); i++) cout << *(customers[i]) << endl;
		else if (choose == 4)
		for (int i = 0; i < admins.size(); i++) cout << *(admins[i]) << endl;
	}
	void Delete(string name) {
		for (int i = 0; i < productItems.size(); i++) {
			if (productItems[i]->getProduct().getName() == name) {
				int len = productItems.size() - 1;
				ProductItem* temp = productItems[len];
				productItems[len] = productItems[i];
				productItems[i] = temp;
				productItems.pop_back();
				return;
			}
		}
	}
	bool checkLogin(Admin* other) {
		for (auto& i : admins) {
			if (*i == *other) return true;
		}return false;
	}
	bool checkLogin(Customer*& other) {
		static bool check = true;
		for (auto& i : customers) {
			if (*i == *other) {
				if (check) {
					other->setId(i->getId());
					other->setCredit(i->getCredit());
					check = false;
				}return true;
			}
		}return false;
	}
	void show() {
		for (int i = 0; i < productItems.size(); i++) {
			cout << "Id : " << productItems[i]->getProduct().getId() << endl;
			cout << "Name : " << productItems[i]->getProduct().getName() << "\n\n";
		}
	}
	ProductItem* getById(int id) {
		for (auto& i : productItems) {
			if (i->getProduct().getId() == id) return i;
		}return new ProductItem();
	}

	// Acsessors

	// Setters

	void setProductItem(ProductItem* productItem) { this->productItems.push_back(productItem); }
	void setOrder(Order* order) { this->orders.push_back(order); }
	void setCustomer(Customer* customer) { this->customers.push_back(customer); }
	void setAdmin(Admin* admin) { this->admins.push_back(admin); }

	// Getters

	const vector<ProductItem*> getProductItems() { return productItems; }
	const vector<Customer*> getCustomers() { return customers; }
	const vector<Admin*> getAdmins() { return admins; }
	const vector<Order*> getOrders() { return orders; }
};
