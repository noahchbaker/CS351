#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
	string name;
	double value;
	double weight;
	
    Item(); //default constructor for array building
	Item(double, double);	
	double ratio() const;
	void print() const;
	bool operator<(const Item &) const;
};

Item::Item() { }

Item::Item(double value_, double weight_) {
    value = value_;
    weight = weight_;
}

double Item::ratio() const {
    return (value / weight);
}

void Item::print() const {
    cout << name << " " << value << " " << weight << " " << ratio() << endl; //idk what it's supposed to print
}

// Compares one item's ratio to another
bool Item::operator<(const Item & right) const {
    double r1 = ratio();
    double r2 = right.ratio();
    return r1 < r2;
}