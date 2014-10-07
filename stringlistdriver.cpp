/*****************************************************************************
Author: Christopher Anzalone
File: stringlistdriver.cpp
Description: This file contains the driver of my user-implemented My_String 
linked list (header) class. It tests each member function's operations of the 
abstract data type that is linked here from the "My_String_List.h" file (and 
from there to the My_String_List.cpp file). 
*****************************************************************************/

#include <iostream>
#include "My_String_List.h"

using namespace std;

void hrLine()
{
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
}

int main ()
{  
	hrLine();
//Default constructor test (with object constructTest1)
	My_String constructTest1;
	constructTest1.Print();

	hrLine();
//Explicit Constructor test (with object expConstrTest1)
		//	char * userChar = new char[32];
		//	cout<<"Please enter characters to be initialized within the string class"<<endl;
		//	cin.get(userChar, 32);

	My_String expConstrTest1("hello");
	expConstrTest1.Print();

	hrLine();
//IsEmpty
	cout<<"Is constructTest1 empty?"<<endl;
	if (constructTest1.IsEmpty() == 1)
		cout<<"... Yes!"<<endl;
	else
		cout<<"... No!"<<endl;

	cout<<"Is expConstrTest1 empty?"<<endl;
	if (expConstrTest1.IsEmpty() == 1)
		cout<<"... Yes!"<<endl;
	else
		cout<<"... No!"<<endl; 
  
	hrLine();
//Copy Constructor

	My_String copyConstrTest1("Bjork");

	My_String copyConstrTest2(copyConstrTest1);   //copy constructor called

	copyConstrTest2.Print();

	hrLine();
//Find
	My_String findTest1("lightyear");
	My_String findTest2("year");

	Node * nodeResult;   //to hold node memory address of find function result below.

	nodeResult = findTest1.Find(findTest2);

	cout<<"Node returned's data:"<<nodeResult->data<<endl;
	cout<<"Node address: "<<nodeResult<<endl;
	cout<<"Note: the Find function is used within the Remove function as well."<<endl;

	hrLine();
//Length
	cout<<"The length of findTest2 ('year') is: "<<findTest2.Length()<<endl; 

	hrLine();
//Remove
	My_String removeTest1("Samsung");
	My_String removeTest2("sung");

	cout<<"Value of removeTest1 before removal: ";
	removeTest1.Print();

	removeTest1.Remove(removeTest2);

	cout<<"Value of removeTest1 after removal: ";
	removeTest1.Print();

	hrLine();
//AddStrings
	My_String addStringsTest1("ABC");
	My_String addStringsTest2("DEF");

	cout<<"addStringsTest1 before adding tenthString to it: ";
	addStringsTest1.Print();

	addStringsTest1.AddStrings(addStringsTest2);

	cout<<"addStringsTest1 after adding tenthString to it: ";
	addStringsTest1.Print();

	hrLine();
//Isequal
	My_String isEqualTest1("hello");
	My_String stringB("hello");

	if ( isEqualTest1.IsEqual(stringB) )
	{
		cout<<"isEqualTest1 is equal to stringB"<<endl;
	}
	else
	{
		cout<<"isEqualTest1 is NOT equal to stringB"<<endl;
	}

	hrLine();
//Setequal
	My_String setEqualTest1("Minecraft");
	My_String setEqualTest2("Notch");

	cout<<"setEqualTest2 BEFORE SetEqual: ";
	setEqualTest2.Print();

	setEqualTest1.SetEqual(setEqualTest2);

	cout<<"setEqualTest2 AFTER SetEqual: ";
	setEqualTest2.Print();

	hrLine();
//Insert
	My_String insertTest1("LCAL");
	My_String insertTest2("OGI");
	cout<<"insertTest1 BEFORE insertion: "<<endl;
	insertTest1.Print();

	insertTest1.Insert(insertTest2, 1);

	cout<<"insertTest1 AFTER insertion: "<<endl;
	insertTest1.Print();

	hrLine();
//Insert when pos < 0
	My_String insertPosTest1A("123");
	My_String insertPosTest1B("456");

	cout<<"insertPosTest1A BEFORE insertion when pos < 0: ";
	insertPosTest1A.Print();
	
	insertPosTest1A.Insert(insertPosTest1B, -2);

	cout<<"insertPosTest1A AFTER insertion when pos < 0: ";
	insertPosTest1A.Print();

	hrLine();
//Insert when pos = 0
	My_String insertPosTest2A("ABC");
	My_String insertPosTest2B("DEF");
	cout<<"insertPosTest2B BEFORE insertion when pos=0: ";
	insertPosTest2B.Print();
	insertPosTest2B.Insert(insertPosTest2A, 0);
	cout<<"insertPosTest2B AFTER insertion when pos=0: ";
	insertPosTest2B.Print();

	hrLine();
//Insert when pos >= string length
	My_String insertPosTest3A("MNO");
	My_String insertPosTest3B("PQR");
	cout<<"insertPosTest3A BEFORE insertion when p >= string: ";
	insertPosTest3A.Print();
	insertPosTest3A.Insert(insertPosTest3B, 4);
	cout<<"insertPosTest3A AFTER insertion when p >= string: ";
	insertPosTest3A.Print();

	hrLine();
//Insert when string and substring have 0 length
	My_String insertBothEmptyTest1, insertBothEmptyTest2;

	insertBothEmptyTest1.Insert(insertBothEmptyTest2, 0);

	hrLine();
//Insert when substring is empty
	My_String insertSubEmptyTest1("Hello");
	My_String insertSubEmptyTest2;

	insertSubEmptyTest1.Insert(insertSubEmptyTest2, 1);

	hrLine();
//Insert when string is empty
	My_String insertEmptyTest1;
	My_String insertEmptyTest2("Data");

	insertEmptyTest1.Insert(insertEmptyTest2, 1);

	hrLine();
//FindLast
	My_String findLastTest1("Banana");
	My_String findLastTest2("an");
	Node * findLastResult = findLastTest1.FindLast(findLastTest2);

	cout<<"Node's returned data: "<<findLastResult->data<<endl;

	cout<<"Node's returned address: "<<findLastResult<<endl;

	hrLine();
	cout<<endl;
	return 0;
}