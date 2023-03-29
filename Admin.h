#pragma once


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