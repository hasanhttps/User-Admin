#pragma once


class Customer final : public Person {
	string username;
	string password;
	int credit;
public:

	// Constructors

	Customer() : credit(0) {}
	Customer(string name, string surname, string username, string password, date dateOfBirth, int credit) :
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