
#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "LinkedListOfInts.h"
#include <vector>
#include <iostream>
#include <string>


class TestSuite
{
	public:
		TestSuite();
		void runTests();
		//void printPassFail(std::string Description, bool isPassed);
		bool test_con();
		bool test_isEmpty();
		bool test_addBack();
		bool test_addFront();
		bool test_removeBack();
		bool test_removeFront();
		bool test_search();
		bool test_size();
		bool test_destructor();

		
	 private:


};
#endif 
