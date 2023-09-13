/*
Here the logic of the program menu is described
*/

#include "Menu.h"
#include "Matric.h"
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <random>

using namespace std;

/*
Global variables
*/

string menuItem;
random_device rd;
mt19937 gen(rd());
bool enableMatrices = true;

/*
Internal functions of the menu.
*/


int Random(int min, int max) {
	std::uniform_int_distribution<> dist(min, max);
	return dist(gen);
}

void ClearMenu() {
	system("cls");
}

void ReadConsole_ToMenuItem() {
	getline(cin, menuItem);
}

void ReadConsole_EnterInput() {
	cout << endl << "Press enter to return to the previous menu."
		<< endl << endl;
	cin.get();
}

bool ShowMaticA() {
	if (MatricA_Empty()) {
		cout << "not set" << endl;
		return false;
	} else {

		if (!enableMatrices) {
			cout << "display disabled" << endl;
			return true;
		}

		for (int i = 0; i < Matrices_GetSize_xA(); i++) {
			cout << endl;
			for (int j = 0; j < Matrices_GetSize_yA_xB(); j++) {
				cout << '\t' << MatricA_GetItem(i, j);
			}
		}
		cout << endl;
	}
	return true;
}

bool ShowMaticB() {
	if (MatricB_Empty()) {
		cout << "not set" << endl;
		return false;
	} else {

		if (!enableMatrices) {
			cout << "display disabled" << endl;
			return true;
		}

		for (int i = 0; i < Matrices_GetSize_yA_xB(); i++) {
			cout << endl;
			for (int j = 0; j < Matrices_GetSize_yB(); j++) {
				cout << '\t' << MatricB_GetItem(i, j);
			}
		}
		cout << endl;
	}
	return true;
}

bool ShowMaticC() {
	if (MatricC_Empty()) {
		cout << "not set" << endl;
		return false;
	} else {

		if (!enableMatrices) {
			cout << "display disabled" << endl;
			return true;
		}

		for (int i = 0; i < Matrices_GetSize_xA(); i++) {
			cout << endl;
			for (int j = 0; j < Matrices_GetSize_yB(); j++) {
				cout << '\t' << MatricC_GetItem(i, j);
			}
		}
		cout << endl;
	}
	return true;
}

/*
Implementing functions from the menu header file
*/

void Menu_Start() {
	
	while (true) {
		
		ClearMenu();
		cout
			<< "Select the menu item and enter the appropriate number." << endl << endl
			<< "1) Set Matrices" << endl
			<< "2) Show Matrices" << endl;
		if (enableMatrices) {
			cout << "3) Disable matrix display" << endl;
		} else {
			cout << "3) Enable matrix display" << endl;
		}
		cout	
			<< "4) Perform matrix multiplication" << endl
			<< "5) Exit the program" << endl << endl
			<< "Enter: ";
		ReadConsole_ToMenuItem();
		
		while (menuItem.size() > 1 || menuItem[0] < '1' || menuItem[0] > '5') {
			cout << "Invalid input. Enter a number from 1 to 5." << endl << endl
				<< "Enter: ";
			ReadConsole_ToMenuItem();
		}
		
		switch (menuItem[0]) {
			case '1': {
				Menu_SetMatrices();
				break;
			}
			case '2': {
				Menu_ShowMatrices();
				break;
			}
			case '3': {
				enableMatrices = enableMatrices ? false : true;
				break;
			}
			case '4': {
				Menu_ExecuteMultiplication();
				break;
			}
			case '5': {
				ClearMenu();
				cout << "The work of the program is completed." << endl << endl;
				return;
			}
		}
	}
}

void Menu_SetMatrices() {
	while (true) {

		ClearMenu();
		cout
			<< "Select the menu item and enter the appropriate number." << endl << endl
			<< "1) Specify the size of the matrices" << endl
			<< "2) Fill in the matrix A" << endl
			<< "3) Fill in the matrix B" << endl
			<< "4) Fill random" << endl
			<< "5) Back" << endl << endl
			<< "Enter: ";
		ReadConsole_ToMenuItem();

		while (menuItem.size() > 1 || menuItem[0] < '1' || menuItem[0] > '5') {
			cout << "Invalid input. Enter a number from 1 to 5." << endl << endl
				<< "Enter: ";
			ReadConsole_ToMenuItem();
		}

		switch (menuItem[0]) {
			case '1': {
				SetMatrices_SetSize();
				break;
			}
			case '2': {
				SetMatrices_SetMatricA();
				break;
			}
			case '3': {
				SetMatrices_SetMatricB();
				break;
			}
			case '4': {
				SetMatrices_SetMatricesRandom();
				break;
			}
			case '5': {
				return;
			}
		}
	}
}

void SetMatrices_SetSize() {
	
	int size;

	Matrices_SetSize_xA(0);
	Matrices_SetSize_yA_xB(0);
	Matrices_SetSize_yB(0);
	MatricA_Delete();
	MatricB_Delete();

	ClearMenu();
	cout << "Enter \'n\'to return without saving." << endl
		<< "Count of rows of matrix A: ";	

	do {

		ReadConsole_ToMenuItem();

		while (sscanf_s(menuItem.c_str(), "%d", &size) != 1) {
		
			if ((menuItem[0] < '0' || menuItem[0] > '9') &&
				(menuItem.size() < 1 || menuItem[0] == 'n')) {
				return;
			}

			cout<< endl
				<< "Invalid input. Enter a number from 1 to 1000." << endl
				<< "Count of rows of matrix A: ";
			ReadConsole_ToMenuItem();
		}

		if (size < 1 || size > 1000) {
			cout << endl
				<< "Invalid input. Enter a number from 1 to 1000." << endl
				<< "Count of rows of matrix A: ";
		}

	} while (size < 1 || size > 1000);

	Matrices_SetSize_xA(size);

	cout << "Count of columns of matrix A and rows of matrix B: ";

	do {

		ReadConsole_ToMenuItem();

		while (sscanf_s(menuItem.c_str(), "%d", &size) != 1) {
		
			if ((menuItem[0] < '0' || menuItem[0] > '9') &&
				(menuItem.size() < 1 || menuItem[0] == 'n')) {
				return;
			}

			cout<< endl
				<< "Invalid input. Enter a number from 1 to 1000." << endl
				<< "Count of columns of matrix A and rows of matrix B: ";
			ReadConsole_ToMenuItem();
		}

		if (size < 1 || size > 1000) {
			cout << endl
				<< "Invalid input. Enter a number from 1 to 1000." << endl
				<< "Count of columns of matrix A and rows of matrix B: ";
		}

	} while (size < 1 || size > 1000);

	Matrices_SetSize_yA_xB(size);

	cout << "Count of columns of matrix B: ";

	do {

		ReadConsole_ToMenuItem();

		while (sscanf_s(menuItem.c_str(), "%d", &size) != 1) {

			if ((menuItem[0] < '0' || menuItem[0] > '9') &&
				(menuItem.size() < 1 || menuItem[0] == 'n')) {
				return;
			}

			cout << endl
				<< "Invalid input. Enter a number from 1 to 1000." << endl
				<< "Count of columns of matrix B: ";
			ReadConsole_ToMenuItem();
		}

		if (size < 1 || size > 1000) {
			cout << endl
				<< "Invalid input. Enter a number from 1 to 1000." << endl
				<< "Count of columns of matrix B: ";
		}

	} while (size < 1 || size > 1000);

	Matrices_SetSize_yB(size);
}

void SetMatrices_SetMatricA() {
	
	stringstream stream;
	string word;
	int item, count;

	ClearMenu();
	cout << "Enter \'n\'to return without saving." << endl
		<< "Matrix Size: "
		;
	if (Matrices_SizeEmpty()) {
		cout << "not set" << endl;
		ReadConsole_EnterInput();
		return;
	}

	cout << Matrices_GetSize_xA() << 'x' << Matrices_GetSize_yA_xB() << endl << endl
		<< "Enter the numbers into the matrix line by line. The numbers are separated by a space." 
		<< endl << endl;
	
	MatricA_Delete();
	MatricA_Init();

	for (int i = 0; i < Matrices_GetSize_xA(); i++) {
		
		cout << "String " << int(i + 1) 
			<< " (" << Matrices_GetSize_yA_xB() << " numbers are expected): ";
		ReadConsole_ToMenuItem();
		
		stringstream().swap(stream);
		stream << menuItem;

		count = 0;
		while (stream >> word) {

			if (sscanf_s(word.c_str(), "%d", &item) != 1) {
				if ((menuItem[0] < '0' || menuItem[0] > '9') &&
					(menuItem.size() < 1 || menuItem[0] == 'n')) {
					return;
				}
				count--;
				break;
			}

			if (count == Matrices_GetSize_yA_xB()) {
				count--;
				break;
			}

			MatricA_SetItem(i, count, item);
			count++;
		}

		if (count < Matrices_GetSize_yA_xB()) {
			cout << endl << "Invalid input. "
				<< Matrices_GetSize_yA_xB() << " numbers are expected." << endl;
			i--;
		}
	}
}

void SetMatrices_SetMatricB() {

	stringstream stream;
	string word;
	int item, count;

	ClearMenu();
	cout << "Enter \'n\'to return without saving." << endl
		<< "Matrix Size: "
		;
	if (Matrices_SizeEmpty()) {
		cout << "not set" << endl;
		ReadConsole_EnterInput();
		return;
	}

	cout << Matrices_GetSize_yA_xB() << 'x' << Matrices_GetSize_yB() << endl << endl
		<< "Enter the numbers into the matrix line by line. The numbers are separated by a space."
		<< endl << endl;

	MatricB_Delete();
	MatricB_Init();

	for (int i = 0; i < Matrices_GetSize_yA_xB(); i++) {

		cout << "String " << int(i + 1)
			<< " (" << Matrices_GetSize_yB() << " numbers are expected): ";
		ReadConsole_ToMenuItem();

		stringstream().swap(stream);
		stream << menuItem;

		count = 0;
		while (stream >> word) {

			if (sscanf_s(word.c_str(), "%d", &item) != 1) {

				if ((menuItem[0] < '0' || menuItem[0] > '9') &&
					(menuItem.size() < 1 || menuItem[0] == 'n')) {
					return;
				}
				count--;
				break;
			}

			if (count == Matrices_GetSize_yB()) {
				count--;
				break;
			}

			MatricB_SetItem(i, count, item);
			count++;
		}

		if (count < Matrices_GetSize_yB()) {
			cout << endl << "Invalid input. "
				<< Matrices_GetSize_yB() << " numbers are expected." << endl;
			i--;
		}
	}
}

void SetMatrices_SetMatricesRandom() {
	;
	if (Matrices_SizeEmpty()) {
		ClearMenu();
		cout << "Matrix Size: not set" << endl;
		ReadConsole_EnterInput();
		return;
	}

	MatricA_Delete();
	MatricA_Init();

	for (int i = 0; i < Matrices_GetSize_xA(); i++) {
		for (int j = 0; j < Matrices_GetSize_yA_xB(); j++) {
			MatricA_SetItem(i, j, Random(1, 100));
		}
	}

	MatricB_Delete();
	MatricB_Init();

	for (int i = 0; i < Matrices_GetSize_yA_xB(); i++) {
		for (int j = 0; j < Matrices_GetSize_yB(); j++) {
			MatricB_SetItem(i, j, Random(1, 100));
		}
	}

	Menu_ShowMatrices();
}

void Menu_ShowMatrices() {

	ClearMenu();
	cout << "Matrix A: " ;

	ShowMaticA();

	cout << endl << endl << "Matrix B: ";

	ShowMaticB();

	cout << endl;
	ReadConsole_EnterInput();
}

void Menu_ExecuteMultiplication() {
	while (true) {
		
		ClearMenu();
		cout
			<< "Select the menu item and enter the appropriate number." << endl << endl
			<< "1) Specify the size of the matrix block" << endl
			<< "2) Block multiplication \"STANDARD\"" << endl
			<< "3) Block multiplication \"PARALLEL\" (upper level)" << endl
			<< "4) Block multiplication \"PARALLEL\" (lower level)" << endl
			<< "5) Block multiplication \"PARALLEL\" (full)" << endl
			<< "6) Back" << endl << endl
			<< "Enter: ";
		ReadConsole_ToMenuItem();
		
		while (menuItem.size() > 1 || menuItem[0] < '1' || menuItem[0] > '6') {
			cout << "Invalid input. Enter a number from 1 to 6." << endl << endl
				<< "Enter: ";
			ReadConsole_ToMenuItem();
		}
		
		switch (menuItem[0]) {
			case '1': {
				ExecuteMultiplication_SetBlockSize();
				break;
			}
			case '2': {
				ExecuteMultiplication_Standard();
				break;
			}
			case '3': {
				ExecuteMultiplication_Parallel_Up();
				break;
			}
			case '4': {
				ExecuteMultiplication_Parallel_Down();
				break;
			}
			case '5': {
				ExecuteMultiplication_Parallel_All();
				break;
			}
			case '6': {
				return;
			}
		}
	}
}

void ExecuteMultiplication_SetBlockSize() {

	int size = 0;

	Matrices_SetBlockMatricSize(1);

	ClearMenu();
	cout << "Enter \'n\'to return without saving." << endl << endl
		<< "Information: The default matrix block size is 1. " << endl
		<< "Specify the block size in the range from 1 to 999." << endl
		<< "The block size should not exceed the number of columns for " << endl
		<< "matrix A and the number of rows for matrix B." << endl << endl
		<< "The size of the matrix block must not exceed: ";

	if (Matrices_SizeEmpty()) {
		cout << "not set" << endl;
		ReadConsole_EnterInput();
		return;
	}

	cout << Matrices_GetSize_yA_xB() << endl << endl << "Matrices Block Size: ";

	do {

		ReadConsole_ToMenuItem();

		while (sscanf_s(menuItem.c_str(), "%d", &size) != 1) {

			if ((menuItem[0] < '0' || menuItem[0] > '9') &&
				(menuItem.size() < 1 || menuItem[0] == 'n')) {
				return;
			}

			cout << endl
				<< "Invalid input. Enter a number from 1 to "
				<< Matrices_GetSize_yA_xB() << "." << endl
				<< "Matrices Block Size: ";
			ReadConsole_ToMenuItem();
		}

		if (size < 1 || size > Matrices_GetSize_yA_xB()) {
			cout << endl
				<< "Invalid input. Enter a number from 1 to "
				<< Matrices_GetSize_yA_xB() << "." << endl
				<< "Matrices Block Size: ";
		}

	} while (size < 1 || size > Matrices_GetSize_yA_xB());

	Matrices_SetBlockMatricSize(size);

}

void ExecuteMultiplication_Standard() {

	ClearMenu();
	cout << "Matrix A: ";

	if (!ShowMaticA()) {
		return;
	}

	cout << endl << endl << "Matrix B: ";

	if (!ShowMaticB()) {
		return;
	}

	MatricC_Delete();
	MatricC_Init();

	cout << fixed << endl << endl
		<< "Block multiplication execution time: "
		<< Matrices_MultiplicationStandard()
		<< "sec" << endl << endl << "Matrix C: ";

	ShowMaticC();

	cout << endl;
	ReadConsole_EnterInput();
}

void ExecuteMultiplication_Parallel_Up() {

	ClearMenu();
	cout << "Matrix A: ";

	if (!ShowMaticA()) {
		return;
	}

	cout << endl << endl << "Матрица B: ";

	if (!ShowMaticB()) {
		return;
	}

	MatricC_Delete();
	MatricC_Init();

	cout << fixed << endl << endl
		<< "Block multiplication execution time: "
		<< Matrices_MultiplicationParallel_Up()
		<< "sec" << endl << endl << "Matrix C: ";

	ShowMaticC();

	cout << endl;
	ReadConsole_EnterInput();
}

void ExecuteMultiplication_Parallel_Down() {

	ClearMenu();
	cout << "Matrix A: ";

	if (!ShowMaticA()) {
		return;
	}

	cout << endl << endl << "Матрица B: ";

	if (!ShowMaticB()) {
		return;
	}

	MatricC_Delete();
	MatricC_Init();

	cout << fixed << endl << endl
		<< "Block multiplication execution time: "
		<< Matrices_MultiplicationParallel_Down()
		<< "sec" << endl << endl << "Matrix C: ";

	ShowMaticC();

	cout << endl;
	ReadConsole_EnterInput();
}

void ExecuteMultiplication_Parallel_All() {

	ClearMenu();
	cout << "Matrix A: ";

	if (!ShowMaticA()) {
		return;
	}

	cout << endl << endl << "Матрица B: ";

	if (!ShowMaticB()) {
		return;
	}

	MatricC_Delete();
	MatricC_Init();

	cout << fixed << endl << endl
		<< "Block multiplication execution time: "
		<< Matrices_MultiplicationParallel_All()
		<< "sec" << endl << endl << "Matrix C: ";

	ShowMaticC();

	cout << endl;
	ReadConsole_EnterInput();
}