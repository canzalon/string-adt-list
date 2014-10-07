/*****************************************************************************
Author: Christopher Anzalone
File: My_String_List.cpp
Description: This file contains the implementation of the My_String_List 
class. The declaration is located in the "My_String_List.h" file. The 
functions are in the following order (same order in header file), ctrl+f the 
tags:
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

#include <iostream>
#include "My_String_List.h"

using namespace std;


//**********************************************************************************************
//NAME:  My_String (default constructor)    (#0)
//DESCRIPTION:  The default constructor will initialize the state of the object.
//PRECONDITION:  Declared in driver.		
//POSTCONDITION:  Object's state initialized. Dynamic memory allocated.
//**********************************************************************************************
My_String::My_String() 
{
	cout<<"Default Constructor has been called."<<endl;

	front = new Node;
	front->next = 0; 
}


//**********************************************************************************************
//NAME:  My_String (explicit constructor)    (#1)
//DESCRIPTION:  Explicit-value constructor that initializes the state of the class with 
//              the specified value.
//PRECONDITION:  Char array parameter in variable declaration.	
//POSTCONDITION:  Object has been initialized with the specified value.
//**********************************************************************************************
My_String::My_String(char * item) 
{
	cout<<"Explicit constructor has been called."<<endl;

	front = new Node;
	front->next = 0;

	int count=0;
	int track=0;

	while (item[count] != '\0')
	{
		count++;
	}

	//create first node (after header) with first char in string
	Node * tempNode = new Node;
	tempNode->data = item[track++];
	tempNode->next = 0;

	//point header node to this first node
	front->next = tempNode;

	//take away address from tempNode for later use with new nodes
	tempNode=0;   //MAY not need this--will test later

	//don't need while loop to bring to end of list, because we know what's what
	Node * p = front->next;    //this points tempNode to the first node in the list (post header)

	//loop to add the rest of the characters to list
	while (track < count)
	{
		tempNode = new Node;
		tempNode->data = item[track++];
		tempNode->next = 0;

		p->next = tempNode;

		p=p->next;
	}
}


//**********************************************************************************************
//NAME:  My_String (copy constructor)    (#2)
//DESCRIPTION:  This is the copy constructor, which makes a deep copy of itself for a
//              call-by-value, return, or intialization/declaration.
//PRECONDITION:  Current object exists and is initialized.		
//POSTCONDITION:  Deep copy of current object has been returned.
//**********************************************************************************************
My_String::My_String(My_String & Ext) 
{
	cout<<"Copy Constructor has been called"<<endl;

	front = new Node;
	front->next = 0;

	Node * q = Ext.front->next;    //keeps track of external object
	Node * p = front;   //keeps track of current object's list (trails behind q's parallel pos in ext object)

	//copy first node, then point header to it, establishing the list
	Node * tempNode = new Node;
	tempNode->data = q->data;
	tempNode->next = 0;
	front->next = tempNode;
	
	p = p->next;
	q = q->next;

	tempNode = 0;  //free the pointer

	while (q!=0)
	{
		tempNode = new Node;         //allocate memory for a new node
		tempNode->data = q->data;    //copy data from corresponding node
		tempNode->next = 0;          //since this node will be put at end of list, it points to null.

		p->next = tempNode;      //add node to the list by pointing last node in list to temp node.

		p = p->next;   //move current object's tracker to point to new node

		q = q->next;   //move external object tracker to next node over to be copied

		tempNode = 0;   //free temp pointer for next node's allocation
	}
}


//**********************************************************************************************
//NAME:  ~My_String (destructor)    (#3)
//DESCRIPTION:  Deallocates dynamic memory and sets the state variables to null.
//PRECONDITION:  Object has been declared/initialized.				
//POSTCONDITION:  Object state has been nullified and deallocated.
//**********************************************************************************************
My_String::~My_String()    //destructor
{
	cout<<"Destructor has been called"<<endl;

	Node * nodeCtrl;

	while (front->next != 0)
	{
		nodeCtrl = front->next;
		front->next = nodeCtrl->next;

		delete nodeCtrl;
	}

	delete front;
}


//**********************************************************************************************
//NAME:  IsEmpty    (#4)
//DESCRIPTION:  Checks if object's state (string) is empty.
//PRECONDITION:  Object has been declared.				
//POSTCONDITION:  Boolean value returned; true if not empty, false if it is.
//**********************************************************************************************
bool My_String::IsEmpty()
{
	if (front->next == 0)
		return 1;
	else
		return 0;
}


//**********************************************************************************************
//NAME:  Length    (#5)
//DESCRIPTION:  Returns length of string.
//PRECONDITION:  Object has been declared/initialized.			
//POSTCONDITION:  Number specifiying length of string returned.
//**********************************************************************************************
int My_String::Length()
{
	Node * p = front->next;    //declare node pointer for moving through list
	int count = 0;     //count variable

	//this counts each node in the list with the node pointer as a guide
	while (p != 0)   
	{
		count++;
		p=p->next;
	}

	return count;
}


//**********************************************************************************************
//NAME:  Insert    (#6)
//DESCRIPTION:  Inserts substring into another string at pos. Cases covered: pos < 0 , pos=0 , 
//              p=[0,length-1] , p > length, p = length , string length = 0 , substring 
//              length = 0 , substring AND string length = 0.
//PRECONDITION:  Two objects have been declared/initialized; value for pos has been established. 		
//POSTCONDITION:  Substring has been inserted at specified point in string.
//**********************************************************************************************
void My_String::Insert(My_String & Ext, int pos)  //note: pos var represents nodes in the same way arrays are; node '0' to node 'n'
{   
	if ( (*this).Length() == 0 && Ext.Length() == 0 )
	{
		cout<<"String and substring are empty; can not insert anything."<<endl;
	}
	else if ( Ext.IsEmpty() )    //if substring is empty
	{
		cout<<"Substring is empty; there is nothing to insert."<<endl;
	}
	else if ( (*this).Length() == 0 )   //if string is empty  //~~~THIS IS CRASHING, FIGURE OUT WHY
	{
		cout<<"String is empty; there is nothing to insert into."<<endl;
	} 
	else if (pos <= 0)  //if position is less than or equal to 0
	{
		Node * thisPtr = (*this).front->next;   //pointer for string to keep track of node that remains after the newly copied substring
		Node * extPtr = Ext.front->next;    //substring pointer to move through substring whilst copying its contents
		Node * backPtr = (*this).front;   //string pointer used to add each newly copied node to the string list

		while (extPtr != 0)  //loops through entire substring
		{
			Node * tempNode = new Node;   //allocate memory for new node in string
			tempNode->data = extPtr->data;   //copy data from substring to new node
			tempNode->next = thisPtr;   //point the new node to the node that comes after the substring's position in the string
			backPtr->next = tempNode;   //this points the already added substring nodes, to the substring nodes that come next

			tempNode = 0;    //free up temp node pointer

			extPtr = extPtr->next;   //move substring pointer over in order to copy over the next node, in the next loop
			backPtr = backPtr->next;   //move back pointer for string to next node in order to append the new nodes 
			                           //in the proper order.
		}
	}
	else if ( (pos) >= ((*this).Length() - 1) )   //if pos var is greater than or equal to the string length
	{
		(*this).AddStrings(Ext);   //the AddStrings function is called to add substring to the end of the string list.
	}
	else
	{
		//this is last case
		Node * thisPtr = (*this).front->next;   //pointer for current string
		Node * extPtr = Ext.front->next;   //this pointer points at start of substring until we are ready to insert it into the string
		Node * backThisPtr = (*this).front->next; //this pointer will keep track of the node that comes after the last node of the substring

		for (int x = 0; (x < pos); x++)
		{
			backThisPtr = backThisPtr->next;  //This moves the pointer to the node at the end of the list
		}

		for (int x = 0; (x < pos - 1); x++)
		{
			thisPtr = thisPtr->next;  //This moves the pointer to the node that points to where substring will be inserted
		}

		while (extPtr != 0)   //while the substring pointer is not at end of list..
		{
			Node * tempNode = new Node;    //allocates memory for new node
			tempNode->data = extPtr->data;   //data from current node in substring copied
			tempNode->next = backThisPtr;   //temp node points to node in string that comes after substring 
			thisPtr->next = tempNode;   //points string to new node that came from the substring

			tempNode = 0;  //free up the temp pointer

			thisPtr = thisPtr->next;   //moves pointer for the string, giving us the ability to point the
									   //list to each new node.
			extPtr = extPtr->next;   //move substring pointer over in order to copy over the next node, in the next loop
		}
	}
}


//**********************************************************************************************
//NAME:  Remove    (#7)
//DESCRIPTION:  Removes the first occurence of a substring from the string, if it exists.
//PRECONDITION:  Current My_String object holds values in list, as well as the "substring"
//               My_String object.
//POSTCONDITION:  If it exists and current object's list is not empty, then the substring 
//                has been removed.
//**********************************************************************************************
void My_String::Remove(My_String & Ext)
{
	if ((*this).IsEmpty())   //check if string is empty
	{
		cout<<"Unable to remove; string is empty."<<endl;
	}
	else  //if substring is larger than string then the substring is not inside the string, can not remove
	{
		if (Ext.Length() > (*this).Length())
		{
			cout<<"Unable to remove; substring is larger than string."<<endl;
		}
		else
		{//if substring is not inside the string, then you can not remove it.
			if ((*this).Find(Ext) == 0)
			{
				cout<<"Unable to remove; there is no occurance of the substring."<<endl;
			}
			else   //substring is < or equal in size to the string, and it does exist in the string..
			{
				Node * ptrFound = (*this).Find(Ext);   //holds value of location to node in list where substring begins
				Node * ptrTrail = (*this).front->next;  //this pointer, initialized to the front of the list, will be..
														//sent to the node that points to the first node to be removed.

				//move trail pointer to node that points to the first node to be removed.
				while (ptrTrail->next != ptrFound)
				{
					ptrTrail = ptrTrail->next;
				}

				//now begin to remove as many nodes (starting at pos of substring) as there are nodes in the substring.
				for (int y=0; y < Ext.Length(); y++)
				{
					ptrTrail->next = ptrFound->next;   //point node before node-to-be-removed, to the node after node being removed.
					delete ptrFound;   //delete memory for node that is being skipped over.
					ptrFound = ptrTrail->next;   //move found pointer to next node that is to be removed.
				}

				//set pointers to null
				ptrFound = 0;
				ptrTrail = 0;

				cout<<"Substring has been removed successfully."<<endl;
			} //else statement
		} //else statement
	} //outer else statement
} //end of function


//**********************************************************************************************
//NAME:  Print    (#8)
//DESCRIPTION:  Prints current object's string.
//PRECONDITION:  Object has been declared/initialized. The string variable holds a value/values.			
//POSTCONDITION:  Object's string has been printed.
//**********************************************************************************************
void My_String::Print()
{
	cout<<"Print function called.."<<endl;

	Node * p = front->next;

	while (p != 0)
	{
		cout<<p->data;
		p = p->next;
	}

	cout<<endl;
}


//**********************************************************************************************
//NAME:  IsEqual    (#9)
//DESCRIPTION:  Checks equality of two My_String objects.
//PRECONDITION:  Two My_String objects exist and hold char value(s). 
//POSTCONDITION:  A boolean value is returned; true if they are equal, false if they are not.
//**********************************************************************************************
bool My_String::IsEqual(My_String & Ext)
{
	//node pointers, one for each list, to guide through each node
	Node * thisPtr = front->next;
	Node * extPtr = Ext.front->next;

	//if the lists are the same size, the node-by-node comparison begins
	if ((*this).Length() == Ext.Length())
	{

		//loop until the pointers reach the end of the list
		while ((thisPtr != 0) && (extPtr != 0))
		{
			//if the current corresponding nodes are equal, move pointers to next node
			if (thisPtr->data == extPtr->data)
			{
				thisPtr = thisPtr->next;
				extPtr = extPtr->next;
			}
			else     //if current list nodes are NOT equal, return false.
			{
				return 0;
			}
		}

		return 1;    //if every iteration of the loop is finished, then the lists are equal
	}
	else     //if the lists have a different length, they are not equal
	{
		return 0;
	}
}


//**********************************************************************************************
//NAME:  SetEqual    (#10)
//DESCRIPTION:  Sets a My_String object equal to another.
//PRECONDITION:  Two Objects have been declared/initialized.
//POSTCONDITION:  Explicit object's state has been set equal to current object's state.
//**********************************************************************************************
void My_String::SetEqual(My_String & Ext)
{
	//deconstruct the Ext string first so that it becomes an empty list
	Node * nodeCtrl;

	while (Ext.front->next != 0)
	{
		nodeCtrl = Ext.front->next;
		Ext.front->next = nodeCtrl->next;

		delete nodeCtrl;
	}

	nodeCtrl = 0; 

	//now that Ext string is empty, we will make copies of each node 
	//..from the current object for the Ext string.
	Node * thisPtr = front->next;   //set pointer to first node in current string's list
	Node * extPtr = Ext.front;    //pointer for ext string

	//establishing the beginning of the list with the first node
	Node * tempNode = new Node;    //new node memory for list
	tempNode->data = thisPtr->data;   //copy data from first node into temp node
	tempNode->next = 0;   //set temp's next to null because it will be last in the list when added
	Ext.front->next = tempNode;   //point header node to temp node, establishing first node in the list

	tempNode = 0;   //set pointer to null

	//move pointers over
	thisPtr = thisPtr->next;
	extPtr = extPtr->next;

	while (thisPtr != 0)  //will stop looping when the end of the current obj's string is reached
	{
		Node* tempNode = new Node;   //allocate memory for new node
		tempNode->data = thisPtr->data;   //set current node's data from current obj's string equal to temp node's data
		tempNode->next = 0;   //point it to null since it will be the last node in the list when added
		extPtr->next = tempNode;   //add new node to ext string list
		
		tempNode = 0;   //set temp pointer to null

		//move pointers over
		thisPtr = thisPtr->next;
		extPtr = extPtr->next;
	}
}

//**********************************************************************************************
//NAME:  Find    (#11)
//DESCRIPTION:  Finds index of string value inside string. Finds string a in string b
//PRECONDITION:  Two string objects have been declared/initialized.	
//POSTCONDITION:  Index of string returned, or -1 if not found.
//**********************************************************************************************
Node * My_String::Find(My_String & Ext)
{
	if ((*this).IsEmpty())
	{
		cout<<"Nothing could be found; string is empty."<<endl;
		return 0;
	}
	else   //if string is not empty
	{
		if (Ext.Length() > (*this).Length())    //if substring is larger than current object, it is not within the string.
		{
			cout<<"Nothing could be found; the substring is larger than the string."<<endl;
			return 0;
		}
		else     //if substring is smaller or equal to the current object in length, then it could be there.
		{   
			Node * thisPtr = (*this).front->next;   //current object's list pointer 
			Node * extPtr = Ext.front->next;     //external object's list pointer (this will never stray from the 
												 //first node, only it's temporary counterpart will, below).
			//while loop count is less than current string's length, and while thisPtr is not null (or, end of list)..
			for (int x=0; (x < (*this).Length()) && (thisPtr != 0); x++)  
			{//outer loop that will compare first letter of substring, and goes
			 //..through the entire current object's string.
				if (extPtr->data == thisPtr->data)
				{//temp pointers here for temporary movement through each string
					Node * tempThisPtr = thisPtr;   //the current pos of the outer loop
					Node * tempExtPtr = extPtr;  //the pos of the first node in the substring

					//iterate through substring and subsequent nodes in current String to see if its full match
					bool misMatch = 0;
					//while the loop count is < substring's length, and while there is no mismatch
					for (int y=0; ( y < Ext.Length() ) && ( misMatch == 0 ); y++)
					{
						if (tempThisPtr->data == tempExtPtr->data)
						{
							tempThisPtr = tempThisPtr->next;
							tempExtPtr = tempExtPtr->next;
						}
						else
						{
							misMatch=1;
						}

					}

					if (misMatch == 0)
					{
						return thisPtr;  //thisPtr represents current (outer) iteration of String
					}

					/*now add updates to pointers for next (outer) iteration, since at this point there is no match..*/

					//move pointer for the current string to next node for the next outer loop's first-letter comparison.
					thisPtr = thisPtr->next;

					//point temp pointers to null for good measure..
					tempThisPtr = 0;
					tempExtPtr = 0;

				}

					/*IF FULL MATCH, RETURN STATEMENT HERE FOR POS AT x*/
					/*ELSE RUN THE SAME STATEMENTS IN THE OUTSIDE ELSE STATEMENT BELOW*/
				else 
				{
					thisPtr = thisPtr->next;   //move pointer for current object to next node, as the next loop will move to next node
											   //(OR, add a condition to the outer loop to stop when thisPtr==0 ) ~~!!!!!!
				}  //else statement
			}  //for loop

			//if you make it outside the for loop, there are no matches in the string, return false.
			cout<<"No matches were found."<<endl;
			return 0;
		} //else statement

		//summary of outer else statement:
		//traverse through the list until there is a first-letter match of the substring. if there is, 
		//start another loop to scan the substring against the current pos in the String and on, for how-
		//ever long the substring is. if the loop iterates for however many characters are in the substring, 
		//then there is a match and the pos of the first-letter-match in the String should be returned.
		//On the other hand, if the first-letter-match loop (outer loop) fully iterates through the entire 
		//String, then no match was found and 0 is returned.
	}
}


//**********************************************************************************************
//NAME:  FindLast    (#12)
//DESCRIPTION:  Finds last instance of substring within a string.
//PRECONDITION:  Two string Objects have been declared/initialized.
//POSTCONDITION:  Index of last instance of sub string returned.
//**********************************************************************************************
Node * My_String::FindLast(My_String & Ext)
{
	if ( (*this).Find(Ext) == 0 )
	{
		return 0;
	}
	else
	{ 
		Node * backPtr = front->next;  //keeps track of backwards stepping through string
		Node * trackPtr = front;
		int searchCount = 0;

		//move back p ointer to last node in list; develop a count for controlling the Find function later on.
		while (backPtr->next != 0)
		{
			backPtr = backPtr->next; 
		}

		//last step in setting up for the full scan: start backPtr where the last substring can be possible.
		for (int x = 0; ( x < (Ext.Length() - 1)); x++)   //to move backPtr forward to leave enough room for first possible match
		{   //this bit of code pulls the backPtr pointer forward (towards front) in the list by one node/
			while (trackPtr->next != backPtr)
			{
				trackPtr = trackPtr->next;  //brings track pointer to node that comes before node pointed at by backPtr
			}

			backPtr = trackPtr;  //moves backPtr over one node, toward front

			trackPtr = front;  //point track pointer to beginning of list for next loop to pull back further, if needed
		}
		
		Node * extPtr = Ext.front->next;

		while (backPtr != front)
		{
			Node * backPtrHold = backPtr; //used if substring doesnt match to put ptrs back in place

			int nodeMatches = 0;  //to keep track of how many node matches 

			if (backPtr->data == extPtr->data)  //if first letters match..
			{
				for (int x = 0; x < Ext.Length(); x++)   //scan for as many times as there are nodes in substring
				{
					if (backPtr->data != extPtr->data)  //if data does not match, break from loop
					{
						break;
					}
					else   //if data in nodes matches, update pointers and increment the tally
					{
						nodeMatches++;
						backPtr = backPtr->next;
						extPtr = extPtr->next;
					}


				}

				if (nodeMatches==Ext.Length())  //if match return pointer
				{
					return backPtrHold;
				}
				else    //no match of current substring scan
				{
					backPtr = backPtrHold;   //put backPtr back in original spot

					while (trackPtr->next != backPtr)
					{
						trackPtr = trackPtr->next;  //brings track pointer to node that comes before node pointed at by backPtr
					}

					backPtr = trackPtr;   //move backPtr back one node (toward front)

					extPtr = Ext.front->next;  //reset substring pointer for next scan
				}

			}

				//if out here, set up for next loop, nothing found
			else
			{
			//set up for next loop
				while (trackPtr->next != backPtr)
				{
					trackPtr = trackPtr->next;  //brings track pointer to node that comes before node pointed at by backPtr
				}

				backPtr = trackPtr;   //move backPtr back one node (toward front)

				//dont need extPtr update here, was not modified if in here
			}
		} //while loop for string

		return 0;  //if you get out here there is nothing.
	} //outer else
}

//**********************************************************************************************
//NAME:  AddStrings    (#13)
//DESCRIPTION:  Add two My_String object's strings together.
//PRECONDITION:  Two My_String objects have been declared/initialized.				
//POSTCONDITION:  Current object's string appended to explicit string.
//**********************************************************************************************
void My_String::AddStrings(My_String & Ext)
{
	//declare pointer to move through the current object's string.
	Node * thisPtr = (*this).front->next;   
	//pointer for external string 
	Node * extPtr = Ext.front->next;

	//move pointer to last node in list of current object's string.
	while (thisPtr->next != 0)
	{
		thisPtr = thisPtr->next;
	}

	//Make copy of each node from external string and add them, individually, to internal string
	for (int x=0; (x < Ext.Length()) && (extPtr != 0); x++)
	{
		Node * tempNode = new Node;   //allocate memory for new node
		tempNode->data = extPtr->data;   //assign it's data with that of the current node from external string
		tempNode->next = 0;   //point the new node to null, since it will be placed at the end of the list.

		thisPtr->next = tempNode;   //add the new node to the internal list/string

		tempNode = 0;   //point node pointer to null so you can use it for 

		thisPtr = thisPtr->next;   //move current object's pointer over to new node for next iteration
		extPtr = extPtr->next;
	}

	//set pointers to null
	thisPtr = 0;
	extPtr = 0;
}