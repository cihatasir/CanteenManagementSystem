#include <iostream>
#include <string>
#include <vector>
#include "Management.h"
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <sstream>

//CIHAT ASIR

using namespace std;

void homeScreen()
{
	cout << "\t*****************************************************************************************\n\n" << endl;
	cout << "\t\t\t\t\tCANTEEN MANAGEMENT SYSTEM\n\n" << endl;
	cout << "\t\t\t1. Add New Product" << endl << "\t\t\t" << "2. Edit Product" << endl << "\t\t\t" << "3. Delete Product" << endl << "\t\t\t" << "4. Search Product by Name" << endl << "\t\t\t" << "5. Search Product by ID" << endl << "\t\t\t" << "6. All Products" << endl << "\t\t\t" << "7. Exit" << endl << endl;
	cout << "\n\t*****************************************************************************************\n\t\t\t\t\t\t\t\t\tcreated by CIHAT ASIR\n" << endl;
}

void menu()
{
	string choose;
	CanteenManagement managementMain;

	homeScreen();

	while (true)
	{
	restart:
		managementMain.fillVector(managementMain.managementVector);
		bool isAlpha = true;
		int newSelection = 0;

		cout << "\n\n" << "Please select an option: ";
		cin >> choose;

		for (int i = 0; i < choose.length(); i++) {

			if (isalpha(choose[i])) {

				isAlpha = false;
			}
			newSelection++;
		}

		system("cls");

		homeScreen();

		if (isAlpha && newSelection == 1)
		{
			newSelection = 0;

			stringstream ss;
			ss << choose;
			ss >> newSelection;

			system("cls");

			homeScreen();

			switch (newSelection)
			{
			case 1:
				managementMain.addNewProduct(managementMain.managementVector);
				managementMain.managementVector.clear();
				goto restart;
			case 2:
				managementMain.editProduct(managementMain.managementVector);
				managementMain.managementVector.clear();
				goto restart;
			case 3:
				managementMain.deleteProduct(managementMain.managementVector);
				managementMain.managementVector.clear();
				goto restart;
			case 4:
				managementMain.findProductByName(managementMain.managementVector);
				managementMain.managementVector.clear();
				goto restart;
			case 5:
				managementMain.findProductByID(managementMain.managementVector);
				managementMain.managementVector.clear();
				goto restart;
			case 6:
				managementMain.showAllProduct(managementMain.managementVector);
				managementMain.managementVector.clear();
				goto restart;
			case 7:
				break;
			default:
				cout << "\n\t\t" << "Incorrect Entry Please Try Again" << endl;
				managementMain.managementVector.clear();
				goto restart;
			}
			break;

		}

		else
		{
			cout << "\n\t\t" << "Incorrect Entry Please Try Again" << endl;
			managementMain.managementVector.clear();
		}

	}
}



int main()
{
	menu();

	return 0;
}