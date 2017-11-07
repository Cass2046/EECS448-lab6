#include "TestSuite.h"

using namespace std;

TestSuite::TestSuite()
{
	
}

void TestSuite::runTests()
{

	test_con();
	
	test_addBack();
	test_addFront();
	test_isEmpty();
	test_removeBack();
	test_removeFront();
	test_search();
	test_size();
	test_destructor();
	
}

//test of the constructor
bool TestSuite::test_con()
{
	cout<<"--- Test 1 ---"<<endl;
	
	LinkedListOfInts list;
	bool isPassed = false;
	
	if(list.toVector().size()==0)
	{
		isPassed = true;
	
		cout<<"PASSED---LinkedListOfInts(): The constructor is built. "<<endl;
	}
	else
	{
		isPassed = false;
		cout<<"FAILED---LinkedListOfInts error: The constructor is not built well. "<<endl;
	}
	cout<<""<<endl;
	return isPassed;

}



//test for add back 
bool TestSuite::test_addBack()
{
	cout<<"--- Test 2 ---"<<endl;
	bool isPassed = true;
	LinkedListOfInts list;

	//add 1-20 to the list
	cout<<"insert 20 nodes (at the back)"<<endl;
	for (int i=1; i<=20; i++)
	{
		list.addBack(i);
		if (list.toVector().back()!=i)
		{
			isPassed = false;
		}
		// cout<<"The size is: "<<list.toVector().size()<<"now,  ";
	}
	//print the whole list
	cout<<"Now, the list is: ";
	for (int i=1; i<=20; i++)
	{
		cout<<list.toVector().at(i-1)<<",";
	}
	cout<<"\n";
	cout<<"The correct list: ";
	for (int i=1; i<=20; i++)
	{
		cout<<i<<",";
	}
	
	cout<<""<<endl;
	if (isPassed==true)
	{
		cout<<"PASSED---addBcak passed: nodes are added to the back of the linked list."<<endl;
	}
	else
	{	
		cout<<"FAILED---addBack error: it doesn't add the node at the back correctly. "<<endl;
	
	}
	cout<<""<<endl;
	return isPassed;
}

//test addFront
bool TestSuite::test_addFront()
{
	cout<<"--- Test 3 ---"<<endl;
	bool isPassed = true;
	LinkedListOfInts list;

	cout<<"insert 20 nodes in the list (at front)"<<endl;
	//add 1-20 to the list
	for (int i=1; i<=20; i++)
	{
		list.addFront(i);
		if (list.toVector().front()!=i)
		{
			isPassed = false;
		}
	}

	//print the whole list
	cout<<"Now, the list is: ";
	for (int i=1; i<=20; i++)
	{
		cout<<list.toVector().at(i-1)<<",";
	}
	cout<<"\n";
	cout<<"The correct list: ";
	for (int i=20; i>=1; i--)
	{
		cout<<i<<",";
	}
	
	cout<<""<<endl;

	if (isPassed==true)
	{
		cout<<"PASSED---addFront passed: nodes are added to the front of the linked list."<<endl;
	}
	else
	{	
		cout<<"FAILED---addFront error: it doesn't add the node at the front correctly. "<<endl;
	}
	cout<<""<<endl;
	return isPassed;

}

//test a empty list
bool TestSuite::test_isEmpty()
{
	cout<<"--- Test 4 ---"<<endl;
	bool isPassed = true;
	LinkedListOfInts list;
	//true case
	if (list.toVector().size()==0)
	{
		if(list.isEmpty()== true)
		{
			cout<<"--->isEmpty: The size is zero for an Empty list."<<endl;
		}
		else
		{
			isPassed = false;
			cout<<"--->isEmpty error: isEmpty does not return true for an empty list."<<endl;
		}
	}
	//false case
	list.addFront(1);
	if (list.toVector().size()!=0)
	{
		if(list.isEmpty()== false)
		{
			cout<<"--->isEmpty: when the size isn't zero, it returns false."<<endl;
		}
		else
		{
			isPassed = false;
			cout<<"--->isEmpty error: isEmpty does not return false for none-empty list."<<endl;
		}
	}
	else
	{
		cout<<"addFront() does not add node to the list."<<endl;
	}
	if (isPassed==true)
	{
		cout<<"PASSED---isEmpty()"<<endl;
	}
	else
	{
		cout<<"FAILED---isEmpty()"<<endl;
	}
	cout<<""<<endl;
	return isPassed;
}

//test removeBack
bool TestSuite::test_removeBack()
{
	cout<<"--- Test 5 ---"<<endl;
	bool isPassed = true;
	LinkedListOfInts list;

	//TEST for an empty list
	if (list.removeBack()==true)
	{
		isPassed=false;
		cout<<"--->Error: removeBack returns true to an empty list."<<endl;
	}
	
	//TEST none-empty list
	//add 1-20 to the list
	list.addFront(1);
	if (list.removeBack()==false)
	{
		cout<<"--->Error: removeBack returns false to none-empty list."<<endl;
	}

	for (int i=1; i<=20; i++)
	{
		list.addFront(i);
	}
	//remove 10 times
	for (int i=1; i<=10; i++)
	{
		list.removeBack();
		// cout<<"Now, the last in the list is "<<list.toVector().back();
		if (list.toVector().back()!=i+1)
		{
			isPassed=false;
		}
	}

	//check wether is it removed
	if(list.toVector().size()!=10)
	{
		cout<<"insert 20 nodes in the list, now "<<list.toVector().size()<<"/21 is in the list after removeback 11 times. "<<endl;
		isPassed=false;
	}

	if (isPassed==true)
	{
		cout<<"PASSED---removeBack passed."<<endl;
	}
	else
	{	
		cout<<"FAILED---removeBack error:add 21 element in the list, remove back 11 times but it doesn't work. "<<endl;
	}

	cout<<""<<endl;
	return isPassed;

}

//test removeFront
bool TestSuite::test_removeFront()
{
	cout<<"--- Test 6 ---"<<endl;
	bool isPassed = true;
	LinkedListOfInts list;
		
	//TEST for an empty list
	if (list.removeFront()==true)
	{
		isPassed=false;
		cout<<"--->Error: removeFront returns true to an empty list."<<endl;
	}
	
	//TEST none-empty list
	//add 1-20 to the list
	list.addFront(1);
	if (list.removeFront()==false)
	{
		cout<<"--->Error: removeFront returns false to none-empty list."<<endl;
	}

	for (int i=1; i<=20; i++)
	{
		list.addFront(i);
	}
	//remove 10 times
	for (int i=1; i<=10; i++)
	{
		list.removeFront();
		if (list.toVector().front()!=20-i)
		{
			isPassed=false;
		}
	}

	//check wether is it removed
	if(list.toVector().size()!=10)
	{
		cout<<"insert 20 nodes in the list, now"<<list.toVector().size()<<"/21 is in the list, after removefront 11 times. "<<endl;
		isPassed=false;
	}

	if (isPassed==true)
	{
		cout<<"PASSED---removeFront passed."<<endl;
	}
	else
	{	
		cout<<"FAILED---removeFront error:add 21 element in the list, remove back 11 times but it doesn't work. "<<endl;
	}

	cout<<""<<endl;
	return isPassed;
}

//test search
bool TestSuite::test_search()
{
	cout<<"--- Test 7 ---"<<endl;
	bool isPassed = true;
	LinkedListOfInts list;

	//search in a empty list
	if(list.search(1)==true)
	{
		isPassed=false;
		cout<<"--->Error: search works in an empty list"<<endl;
	}

	//add 100 elements
	for (int i=1; i<=100; i++)
	{
		list.addFront(i);
	}
	//test for 100 element in the list
	for (int i=1; i<=100; i++)
	{
		if (list.search(i)==false)
		{
			isPassed=false;
			cout<<"--->Eorror: searched elements which exist in the list, but it didn't find them out. "<<endl;
		}
	}

	//test search element not in the list
	if (list.search(200)==true)
	{
		isPassed=false;
		cout<<"FAILED---Eorror: it searched a element that not in the list."<<endl;
	}
	else
	{
		isPassed=true;
		cout<<"PASSED---Search is passed."<<endl;
	}
	cout<<""<<endl;
	return isPassed;

}


//test the size of a list
bool TestSuite::test_size()
{
	cout<<"--- Test 8 ---"<<endl;
	bool isPassed = false;
	bool isPassed1 = true;  	//empty list
	bool isPassed2 = false;		//addfront
	//bool isPassed3 = false;		//removeFront
	LinkedListOfInts list;

	//test the size for an empty list
	if (list.toVector().size()==0)
	{
		
		if (list.size()!=0)
		{
			isPassed1=false;
			cout<<"---Error: The size isn't zero for an empty list."<<endl;
		}

	}

// cout<<list.size()<<endl;
// cout<<list.toVector().size()<<endl;

	//test the size for none-empty list
	//add 20 elements, and elements start from 1 to 20.
	for (int i=1; i<=20; i++)
	{
		list.addFront(i);
		// cout<<"After addFront once "<<endl;
		// cout<<"The size is: "<<list.size()<<endl;
	}

	if (list.size()==20 && list.toVector().size()==20)
	{
		isPassed2=true;
		//cout<<"size is correct with add 20 nodes in the list."<<endl;
	}
	else
	{
		cout<<"---Error: the size is not 20, after addFront 20 times with an empty list.";
	}

	//remove 10 elements, test the size
	// for (int i=0; i<10; i++)
	// {
	// 	list.removeFront();
	// 	cout<<"After removeFront once "<<endl;
	// 	cout<<"The size is: "<<list.size()<<endl;
	// }
	// if(list.size()==10)
	// {
	// 	isPassed3=true;
	// 	cout<<"size is correct with remove 10 nodes in the list."<<endl;
	// }
	
	if(isPassed1==true && isPassed2==true)
	{
		isPassed=true;
		cout<<"PASSED---size() is passed."<<endl;
	}
	else if(isPassed1==false)
	{
		cout<<"1"<<endl;
	}
	else  if (isPassed2==false)
	{
		cout<<"2"<<endl;
	}

	return isPassed;

}


bool TestSuite::test_destructor()
{
	cout<<""<<endl;
	cout<<"--- Test 9 ---"<<endl;
	bool isPassed=false;
	LinkedListOfInts list;
	//add 1-20 to the list
	for (int i=1; i<=20; i++)
	{
		list.addFront(i);
	}

	list.~LinkedListOfInts();
	if (list.toVector().size()==0)
	{
		isPassed=true;
		cout<<"PASSED---test destructor: is passed."<<endl;
	}
	else
	{
		cout<<"FAILED---test destructor has error: it didn't clean the list. "<<endl;
	}
	return isPassed;
}

