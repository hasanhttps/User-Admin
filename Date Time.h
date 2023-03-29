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