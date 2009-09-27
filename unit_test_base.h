#ifndef	__UNIT_TEST_BASE_H__
#define	__UNIT_TEST_BASE_H__

#include <map>
#include <iostream>
#include <string>

using std::map;
using std::cout;
using std::endl;
using std::string;

#define runTestSet(CLASS_NAME, OBJ_NAME) CLASS_NAME OBJ_NAME; OBJ_NAME.runTests()


class UnitTestBase
{
	private:
		typedef map<string, bool>::const_iterator c_test_it;

	public:
		UnitTestBase(const string& testSetName) : m_testSetName(testSetName) {}
		virtual ~UnitTestBase() {}

		virtual void setUp(void) {}
		virtual void tearDown(void) {}
		
		void runTests(void)
		{
			string successMsg = "";
			string failureMsg = "";
			string msg = "";
       
      // Run the tests in the concrete derived test class that inherits from this
      // So this is a generic runner in the base, and runs each test class' tests
      // The derived classes are responsible for writing test* methods, having
      //  those methods call utAssert() with their test name and passed value,
      //  and for putting a call to each test in their runAllTests().
      // Then the unit_test_suite{}::runTestSuite() instantiates each
      //  derived test class and calls its runTests() (this method here)
      //  and main or whatever you want calls runTestSuite()
			runAllTests();

			log("\n************************************");
			msg = "TEST SET: ";
			msg += m_testSetName;
			log(msg);
			log("************************************");

			int count = 0;
			int failCount = 0;
			c_test_it bound = m_tests.end();
			for (c_test_it testIt = m_tests.begin(); testIt != bound; ++testIt, ++count)
			{
				msg = "*****************************\nTest: ";
				msg += testIt->first;
				msg += "\n";
				
				msg += "Result: ";
				if(testIt->second)
				{
					successMsg += msg;
					successMsg += "Success\n";
				}
				else
				{
					++failCount;
					failureMsg += msg;
					failureMsg += "FAILURE\n";
				}
			}
			
			if (failureMsg.length() > 0)
			{
				log("");
				failureMsg += "*****************************";
				log(failureMsg);
			}
			if (successMsg.length() > 0)
			{
				log("");
				successMsg += "*****************************";
				log(successMsg);
			}

			log("\n************************************");
			cout << "TOTAL Tests Run: " << count << "\nSucceeded: " << (count - failCount) << "\nFAILED: " << failCount << endl;
			log("************************************");
			log("");
		}

		virtual void runAllTests() {}
		
		virtual void log(const string& msg)
		{
			cout << msg << endl;
		}

		void utAssert(const string& testName, bool passed)
		{
			m_tests.insert(std::make_pair(testName, passed));
		}

	protected:
		map<string, bool> m_tests;
		string m_testSetName;
};

#endif