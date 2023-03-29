#pragma once


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