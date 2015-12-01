// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	List list;

	int index, value;
	cout << "Enter value to add in begin: ";
	cin >> value;
	list.addInBegin(value);
	cout << "Enter value to add in end: ";
	cin >> value;
	list.addInEnd(value);
	list.show();
	
	cout << "Enter position to add value: ";
	cin >> index;
	cout << "Enter value: ";
	cin >> value;
	list.add((index - 1), value);
	list.show();

	cout << "Enter position to remove value: ";
	cin >> index;
	list.remove(index);
	list.show();

	cout << "Size of list: " << list.size() << endl;
	cout << "Enter position to get value by index: ";
	cin >> index;
	cout << "Value in position " << index << ": " << list.get(index) << endl;

	cout << "Clear list" << endl;
	list.clear();
	list.show();

	system("pause");
	return 0;
}

