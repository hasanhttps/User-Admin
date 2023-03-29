// Necessary Libraries

#include <iostream>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <string>
#include <conio.h>
using namespace std;

// Header Files

#include "Date Time.h"
#include "Person.h"
#include "Customer.h"
#include "Admin.h"
#include "Product.h"
#include "Product Item.h"
#include "Order.h"
#include "Database.h"



int main() {

	// Variables

	Database* database = new Database();
	Customer* checkCustomer = new Customer();
	Admin* checkAdmin = new Admin();
	Customer* newCustomer = new Customer();
	Admin* newAdmin = new Admin();
	int number;
	int loginChoose;
	bool loginedAdmin = false;
	bool loginedCustomer = false;
	bool inLogin = false;


	while (true) {
		system("cls");
		if (!(loginedAdmin || loginedCustomer)) {
			cout << "Welcome To Irshad!!\n\n\n";
			cout << "\t\tCustomer  [1]\n\t\tAdmin     [2]\n\t\tExit      [0]\n\n\nPlease enter the register number : ";
			cin >> number;
			system("cls");
			if (number == 1) {
				cin >> *newCustomer;
				database->setCustomer(newCustomer);
				loginedCustomer = true;
			}
			else if (number == 2) {
				cin >> *newAdmin;
				database->setAdmin(newAdmin);
				loginedAdmin = true;
			}
			else if (number == 0) break;
		}
		if (!inLogin) {
			system("cls");
			cout << "Login Page\n\n";
			cout << "\t\tCustomer  [1]\n\t\tAdmin     [2]\n\t\tExit      [0]\n\nPlease enter the login number : ";
			cin >> loginChoose;
			system("cls");
		}
		if (loginChoose == 1) {
			string username, password;

			if (!inLogin) {
				cout << "Please enter the username : ";
				cin >> username;
				cout << "Please enter the password : ";
				while (true) {
					char ascii = _getch();
					if (ascii == '\r') break;
					password.push_back(ascii);
					cout << "*";
				}cout << endl;
				checkCustomer->setUsername(username);
				checkCustomer->setPassword(password);
			}

			if (database->checkLogin(checkCustomer)) {
				system("cls");
				inLogin = true;
				int choose;
				cout << "Irshad Store\n\n\t\t\t\t\t\t\t\tCredit : " << checkCustomer->getCredit() << endl;
				cout << "Product Count : " << database->getProductItems().size() << "\n\n";
				database->show();
				cout << "\n\n" << "Buy           [1]\nShow Detail   [2]\nExit          [0]\nPlease enter the number : ";
				cin >> choose;
				if (choose == 1) {
					int quantity;
					cout << "Please enter the id : ";
					cin >> choose;
					ProductItem* productbyid = database->getById(choose);
					system("cls");
					cout << "Product Info\n\n";
					cout << *productbyid << endl;
					cout << "Please enter the amount of product that you want buy : ";
					cin >> quantity;
					bool check;
					if (checkCustomer->getCredit() - productbyid->TotalPrice(quantity) < 0) {
						cout << "You don't have enough money!" << endl;
						system("pause");
					}
					else if (quantity > productbyid->getQuantity()) {
						cout << "Not enough product in stock please try lower amount!" << endl;
						system("pause");
					}
					else {
						cout << "Are you sure to buy yes [any]/no [0] : ";
						cin >> check;
						if (check) {
							Order* newOrder = new Order(productbyid, checkCustomer->getId(), __TIME__, quantity);
							database->setOrder(newOrder);
							productbyid->setQuantity(productbyid->getQuantity() - quantity);
							checkCustomer->setCredit(checkCustomer->getCredit() - productbyid->TotalPrice(quantity));
							system("pause");
						}
					}
				}
				else if (choose == 2) {
					cout << "Please enter the id : ";
					cin >> choose;
					ProductItem* productbyid = database->getById(choose);
					system("cls");
					cout << *productbyid << endl;
					system("pause");
				}
				else if (choose == 0) inLogin = false;
			}
		}
		else if (loginChoose == 2) {
			string username, password;
			
			if (!inLogin) {
				cout << "Please enter the username : ";
				cin >> username;
				cout << "Please enter the password : ";
				while (true) {
					char ascii = _getch();
					if (ascii == '\r') break;
					password.push_back(ascii);
					cout << "*";
				}cout << endl;
				checkAdmin->setUsername(username);
				checkAdmin->setPassword(password);
			}
			if (database->checkLogin(checkAdmin)) {
				system("cls");
				inLogin = true;

				int command;
				cout << "\t\tShow All Datas     [1]\n\t\tAdd Product        [2]\n\t\tDelete Product     [3]\n\t\tUpdate Product     [4]\n\t\tExit               [0]\n\n\nPlease choose the number of command : ";
				cin >> command;
				system("cls");
				cin.ignore(1);
				if (command == 1) {
					cout << "\t\tProducts       [1]\n\t\tOrders         [2]\n\t\tCustomers      [3]\n\t\tAdmins         [4]\n\n";
					cout << "Please enter data to show : ";
					cin >> command;
					database->Read(command);
					cout << "Enter any key to continue ...";
					while (!_kbhit()) continue;
					int a = _getch();
				}
				else if (command == 2) {
					database->Create();
				}
				else if (command == 3) {
					string name;
					cout << "Please enter the name of product that you want delete : ";
					getline(cin, name);
					database->Delete(name);
				}
				else if (command == 4) {

				}
				else if (command == 0) {
					inLogin = false;
				}
			}
			else {
				cout << "Acsess Denied !";
			}
		}
		else if (loginChoose == 0) {
			loginedAdmin = false;
			loginedCustomer = false;
		}
	}
	
}