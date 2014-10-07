/*****************************************************************************
Author: Christopher Anzalone
File: My_String_List.h
Description: This file contains the declaration of the My_String_List class. 
The implementation is located in the "My_String_List.cpp" file. The functions 
are in the following order, ctrl+f the tags:
    (#0) My_String [default]
    (#1) My_String [explicit]
    (#2) My_String [copy]
    (#3) ~My_String [destructor]
    (#4) IsEmpty
    (#5) Length
    (#6) Insert
    (#7) Remove
    (#8) Print
    (#9) IsEqual
    (#10) SetEqual
    (#11) Find
    (#12) FindLast
    (#13) AddStrings
*****************************************************************************/

#ifndef MY_STRING_LIST
#define MY_STRING_LIST

class Node
{
public:
	char data;   //holds data for each node (aka, each character)
	Node * next;    //holds memory address of next node in list
};

class My_String
{
public: 

//**********************************************************************************************
//NAME:  My_String (default constructor)    (#0)
//DESCRIPTION:  The default constructor will initialize the state of the object.
//PRECONDITION:  Declared in driver.		
//POSTCONDITION:  Object's state initialized. Dynamic memory allocated.
//**********************************************************************************************
	My_String();  

//**********************************************************************************************
//NAME:  My_String (explicit constructor)    (#1)
//DESCRIPTION:  Explicit-value constructor that initializes the state of the class with 
//              the specified value.
//PRECONDITION:  Char array parameter in variable declaration.	
//POSTCONDITION:  Object has been initialized with the specified value.
//**********************************************************************************************
	My_String(char *);  

//**********************************************************************************************
//NAME:  My_String (copy constructor)    (#2)
//DESCRIPTION:  This is the copy constructor, which makes a deep copy of itself for a
//              call-by-value, return, or intialization/declaration.
//PRECONDITION:  Current object exists and is initialized.		
//POSTCONDITION:  Deep copy of current object has been returned.
//**********************************************************************************************
	My_String(My_String &);   

//**********************************************************************************************
//NAME:  ~My_String (destructor)    (#3)
//DESCRIPTION:  Deallocates dynamic memory and sets the state variables to null.
//PRECONDITION:  Object has been declared/initialized.				
//POSTCONDITION:  Object state has been nullified and deallocated.
//**********************************************************************************************
	~My_String(); 

//**********************************************************************************************
//NAME:  IsEmpty    (#4)
//DESCRIPTION:  Checks if object's state (string) is empty.
//PRECONDITION:  Object has been declared.				
//POSTCONDITION:  Boolean value returned; true if not empty, false if it is.
//**********************************************************************************************
	bool IsEmpty(); 

//**********************************************************************************************
//NAME:  Length    (#5)
//DESCRIPTION:  Returns length of string.
//PRECONDITION:  Object has been declared/initialized.			
//POSTCONDITION:  Number specifiying length of string returned.
//**********************************************************************************************
	int Length(); 

//**********************************************************************************************
//NAME:  Insert    (#6)
//DESCRIPTION:  Inserts substring into another string at pos. Cases covered: pos < 0 , pos=0 , 
//              p=[0,length-1] , p > length, p = length , string length = 0 , substring 
//              length = 0 , substring AND string length = 0.
//PRECONDITION:  Two objects have been declared/initialized; value for pos has been established. 		
//POSTCONDITION:  Substring has been inserted at specified point in string.
//**********************************************************************************************
	void Insert(My_String &, int); 

//**********************************************************************************************
//NAME:  Remove    (#7)
//DESCRIPTION:  Removes the first occurence of a substring from the string, if it exists.
//PRECONDITION:  Current My_String object holds values in list, as well as the "substring"
//               My_String object.
//POSTCONDITION:  If it exists and current object's list is not empty, then the substring 
//                has been removed.
//**********************************************************************************************
	void Remove(My_String &); 

//**********************************************************************************************
//NAME:  Print    (#8)
//DESCRIPTION:  Prints current object's string.
//PRECONDITION:  Object has been declared/initialized. The string variable holds a value/values.			
//POSTCONDITION:  Object's string has been printed.
//**********************************************************************************************
	void Print();

//**********************************************************************************************
//NAME:  IsEqual    (#9)
//DESCRIPTION:  Checks equality of two My_String objects.
//PRECONDITION:  Two My_String objects exist and hold char value(s). 
//POSTCONDITION:  A boolean value is returned; true if they are equal, false if they are not.
//**********************************************************************************************
	bool IsEqual(My_String &);

//**********************************************************************************************
//NAME:  SetEqual    (#10)
//DESCRIPTION:  Sets a My_String object equal to another.
//PRECONDITION:  Two Objects have been declared/initialized.
//POSTCONDITION:  Explicit object's state has been set equal to current object's state.
//**********************************************************************************************
	void SetEqual(My_String &); 

//**********************************************************************************************
//NAME:  Find    (#11)
//DESCRIPTION:  Finds index of string value inside string. Finds string a in string b
//PRECONDITION:  Two string objects have been declared/initialized.	
//POSTCONDITION:  Index of string returned, or -1 if not found.
//**********************************************************************************************
	Node * Find(My_String &); 

//**********************************************************************************************
//NAME:  FindLast    (#12)
//DESCRIPTION:  Finds last instance of substring within a string.
//PRECONDITION:  Two string Objects have been declared/initialized.
//POSTCONDITION:  Index of last instance of sub string returned.
//**********************************************************************************************
	Node * FindLast(My_String &);

//**********************************************************************************************
//NAME:  AddStrings    (#13)
//DESCRIPTION:  Add two My_String object's strings together.
//PRECONDITION:  Two My_String objects have been declared/initialized.				
//POSTCONDITION:  Current object's string appended to explicit string.
//**********************************************************************************************
	void AddStrings(My_String &); 

private:

	Node * front;    //list header aka first node in list

};

#endif