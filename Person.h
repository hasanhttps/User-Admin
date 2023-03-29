#pragma once


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