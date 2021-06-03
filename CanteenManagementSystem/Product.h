#include <iostream>
#include <string>

using namespace std;

class Product {
private:
	string pName, pID, pPrice;
public:
	Product(string, string, string);

	void setpName(string);
	//
	string getpName() const;
	//
	void setpID(string);
	//
	string getpID() const;
	//
	void setpPrice(string);
	//
	string getpPrice() const;
};


Product::Product(string productName, string productID, string productPrice)
{
	pName = productName;
	pID = productID;
	pPrice = productPrice;
}

string Product::getpName() const
{
	return pName;
}

string Product::getpID() const
{
	return pID;
}

string Product::getpPrice() const
{
	return pPrice;
}

void Product::setpName(string productName)
{
	pName = productName;
}

void Product::setpID(string productID)
{
	pID = productID;
}

void Product::setpPrice(string productPrice)
{
	pPrice = productPrice;
}
