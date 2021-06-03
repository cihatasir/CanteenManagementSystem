#include <iostream>
#include "Product.h"
#include <fstream>
#include <string>
#include <string>

using namespace std;

class CanteenManagement {
public:

	vector<Product>managementVector;

	void fillVector(vector<Product>& managementVector);
	void addNewProduct(vector<Product>& managementVector);
	void showAllProduct(vector<Product>& managementVector);
	void findProductByName(vector<Product>& managementVector);
	void findProductByID(vector<Product>& managementVector);
	void deleteProduct(vector<Product>& managementVector);
	void editProduct(vector<Product>& managementVector);
};


void CanteenManagement::fillVector(vector<Product>& managementVector) // pull the data in the data.txt into the vector of product.
{
	string textData;
	string name, id, price;

	vector<string>temporary;

	fstream file;
	file.open("data.txt");

	while (getline(file, textData))
	{
		temporary.push_back(textData); // line-by-line reading and push into temporary vector.
	}

	file.close();

	for (int i = 0; i < temporary.size(); i++)
	{
		name = temporary[i];
		i += 1;
		//
		id = temporary[i];
		i += 1;
		//
		price = temporary[i];
		//
		Product newProduct(name, id, price);
		managementVector.push_back(newProduct);
	}
}

void CanteenManagement::addNewProduct(vector<Product>& managementVector)
{
	string name, id, price;

	cin.ignore();

firstGoto:

	cout << "\n\n" << "Enter Product's Name: ";
	getline(cin, name);


	for (int i = 0; i < managementVector.size(); i++) // If the product you want to add exists in the data, you must enter it again.
	{
		if (managementVector[i].getpName() == name) {
			cout << "\n\n\t" << "It's already added." << endl;
			goto firstGoto;
		}
	}

secondGoto:

	cout << "\n" << "Enter Product's ID: ";
	cin >> id;

	for (int i = 0; i < managementVector.size(); i++) // If the ID of the product you want to add is present in the data, you must enter it again.
	{
		if (managementVector[i].getpID() == id) {
			cout << "\n\n\t" << "It's already added." << endl;
			goto secondGoto;
		}
	}


	cout << "\n" << "Enter Product's Price: ";
	cin >> price;

	Product newProduct(name, id, price);

	fstream file;
	file.open("data.txt", ios::app);

	file << newProduct.getpName() << endl;
	file << newProduct.getpID() << endl;
	file << newProduct.getpPrice() << endl;

}

void CanteenManagement::showAllProduct(vector<Product>& managementVector) // print all products on the screen from vector.
{

	string name, id, price;

	cout << "\n\n\n" << "-------------------------------------------------------------------------" << endl;
	cout << "        Name" << "\t\t\t" << "ID" << "\t\t\t" << "Price" << endl;
	cout << "-------------------------------------------------------------------------" << endl;


	for (int i = 0; i < managementVector.size(); i++)
	{
		if (managementVector[i].getpName().length() >= 10)
		{
			cout << "  " << i + 1 << "." << " " << managementVector[i].getpName();
			cout << "\t\t";
			cout << managementVector[i].getpID();
			cout << "\t\t\t";
			cout << managementVector[i].getpPrice();
			cout << "\n";
		}

		else
		{
			cout << "  " << i + 1 << "." << " " << managementVector[i].getpName();
			cout << "\t\t\t";
			cout << managementVector[i].getpID();
			cout << "\t\t\t";
			cout << managementVector[i].getpPrice();
			cout << "\n";
		}

		cout << endl;
	}

	cout << "-------------------------------------------------------------------------" << endl;
}

void CanteenManagement::findProductByName(vector<Product>& managementVector) // search for products by name from data.
{
	string name, id, price;
	bool counter = false;
	cin.ignore();

	cout << "\n\n" << "Enter You Want Search Item's Name: ";
	getline(cin, name);

	for (int i = 0; i < managementVector.size(); i++)
	{
		if (managementVector[i].getpName() == name)
		{
			cout << "\n\n\t\t\t---- Results ----" << endl << endl << endl;
			cout << "        Name" << "\t\t\t" << "ID" << "\t\t\t" << "Price" << endl;
			cout << "-------------------------------------------------------------------------" << endl << endl;

			if (managementVector[i].getpName().length() >= 10)
			{
				cout << "  " << i + 1 << "." << " " << managementVector[i].getpName();
				cout << "\t\t";
				cout << managementVector[i].getpID();
				cout << "\t\t\t";
				cout << managementVector[i].getpPrice();
				cout << "\n\n";
			}
			else
			{
				cout << "  " << i + 1 << "." << " " << managementVector[i].getpName();
				cout << "\t\t\t";
				cout << managementVector[i].getpID();
				cout << "\t\t\t";
				cout << managementVector[i].getpPrice();
				cout << "\n\n";
			}
			cout << "-------------------------------------------------------------------------" << endl << endl << endl;
			counter = true;
		}
	}
	if (counter == false)
	{
		cout << "\n\t\t)-: Item Not Found :-(" << endl;
	}

}

void CanteenManagement::findProductByID(vector<Product>& managementVector) // search for products by ID from data.
{
	string name, id, price;
	bool counter;
	cin.ignore();

	cout << "\n\n" << "Enter You Want Search Item's ID: ";
	cin >> id;

	for (int i = 0; i < managementVector.size(); i++)
	{
		if (managementVector[i].getpID() == id)
		{
			cout << "\n\n\t\t\t---- Results ----" << endl << endl << endl;
			cout << "        Name" << "\t\t\t" << "ID" << "\t\t\t" << "Price" << endl;
			cout << "-------------------------------------------------------------------------" << endl << endl;

			if (managementVector[i].getpName().length() >= 10)
			{
				cout << "  " << i + 1 << "." << " " << managementVector[i].getpName();
				cout << "\t\t";
				cout << managementVector[i].getpID();
				cout << "\t\t\t";
				cout << managementVector[i].getpPrice();
				cout << "\n\n";
			}
			else
			{
				cout << "  " << i + 1 << "." << " " << managementVector[i].getpName();
				cout << "\t\t\t";
				cout << managementVector[i].getpID();
				cout << "\t\t\t";
				cout << managementVector[i].getpPrice();
				cout << "\n\n";
			}
			cout << "-------------------------------------------------------------------------" << endl << endl << endl;
			counter = true;
		}
	}
	if (counter == false)
	{
		cout << "\n\t\t)-: Item Not Found :-(" << endl;
	}
}


void CanteenManagement::deleteProduct(vector<Product>& managementVector)
{
	string name, id, price;

	bool counter = false;

	cin.ignore();

	cout << "\n\n" << "Enter You Want Remove Product's Name: ";
	getline(cin, name);

	ifstream oldFile;
	oldFile.open("data.txt"); // open old file.

	ofstream newFile;
	newFile.open("data1.txt", ios::app); // open new file.

	for (int i = 0; i < managementVector.size(); i++)
	{
		if (managementVector[i].getpName() == name) // search products by name from the vector, and if there is a match, that product remains in the If block.
		{
			counter = true; // If the product to be deleted cannot be found, it is checked here.
		}

		else // then, a product that does not want to be deleted is registered to a new file in else.
		{
			newFile << managementVector[i].getpName() << endl;
			newFile << managementVector[i].getpID() << endl;
			newFile << managementVector[i].getpPrice() << endl;
		}
	}

	if (counter == false)
	{
		cout << "\n\n\n" << "\n\t\t)-: Product Not Found :-(" << endl;
	}

	else
	{
		cout << "\n\n\n" << "\n\t\t Successfully Deleted " << endl;
	}

	oldFile.close();
	newFile.close();

	remove("data.txt"); // remove old file.
	rename("data1.txt", "data.txt"); // the old file is replaced with the new file name.
}

void CanteenManagement::editProduct(vector<Product>& managementVector)
{
	string name, id, price;

	bool counter = false;

	cin.ignore();

	cout << "\n\n" << "Enter the Name of the Product You Want to Edit: ";
	getline(cin, name);

	ifstream oldFile;
	oldFile.open("data.txt");

	ofstream newFile;
	newFile.open("data1.txt", ios::app);

	for (int i = 0; i < managementVector.size(); i++)
	{
		if (managementVector[i].getpName() == name)
		{
			cout << "\nEnter New Name: ";
			getline(cin, name);

		idCursor:

			cout << "\nEnter New ID: ";
			cin >> id;

			for (int i = 0; i < managementVector.size(); i++)
			{
				if (managementVector[i].getpID() == id) {
					cout << "\n\n\t" << "This id is being used." << endl;
					goto idCursor;
				}
			}

			cout << "\nEnter New Price: ";
			cin >> price;

			Product newProduct(name, id, price); // the edited new product is registered here to the new file.

			newFile << newProduct.getpName() << endl;
			newFile << newProduct.getpID() << endl;
			newFile << newProduct.getpPrice() << endl;

			counter = true;
		}

		else
		{
			newFile << managementVector[i].getpName() << endl; // old registered printed here to the new file.
			newFile << managementVector[i].getpID() << endl;
			newFile << managementVector[i].getpPrice() << endl;
		}
	}

	if (counter == false)
	{
		cout << "\n\n\n" << "\n\t\t)-: Product Not Found :-(" << endl;
	}

	oldFile.close();
	newFile.close();

	remove("data.txt");
	rename("data1.txt", "data.txt");
}