#ifndef	__UNIT_TEST_SUITE_H__
#define	__UNIT_TEST_SUITE_H__

#include <assert.h>

// *** Include each TestSet class header here *** 
#include "pigment_ut.h"
// *** /Include each TestSet class header here ***


class UnitTestSuite
{
	public:
		UnitTestSuite() {}
		~UnitTestSuite() {}

		void runTestSuite(void)
		{
			// *** Add call to TestSet method runTests() here *** 
			Pigment_UT testObj_1;				testObj_1.runTests();
		}

	private:
		UnitTestSuite(const UnitTestSuite&) {assert(false);}
		UnitTestSuite& operator=(const UnitTestSuite&) {assert(false);}
};

#endif