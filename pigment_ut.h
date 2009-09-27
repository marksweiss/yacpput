#ifndef	__PIGMENT_UT_H__
#define	__PIGMENT_UT_H__

#include "pigment.h"
#include "num_traits.h"
#include "unit_test_base.h"


class Pigment_UT : public UnitTestBase
{
	public:
		Pigment_UT() : UnitTestBase("Pigment_UT") {}

		void test_ctor(void)
		{
			bool passed = false;

			Pigment noarg;
			Pigment arg(1.0f, 0.5f, 0.75f);

			passed = true;

			utAssert("test_ctor", passed);
		}

		void test_getSet(void)
		{
			bool passed = false;

			Pigment noarg;

			float expected = 0.0f;
			float actual = noarg.getRedValue();
			passed = num_traits<float>::isEqual(expected, actual);
			if (passed) actual = noarg.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) actual = noarg.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);

			Pigment arg(1.0f, 0.5f, 0.75f);

			if (passed) expected = 1.0f;
			if (passed) actual = arg.getRedValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.5f;
			if (passed) actual = arg.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.75f;
			if (passed) actual = arg.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);

			utAssert("test_getSet", passed);
		}

		void test_copyAndAssignment(void)
		{
			bool passed = false;

			Pigment noarg1;
			Pigment noarg2(noarg1);	// copy from default values

			float expected = 0.0f;
			float actual = noarg1.getRedValue();
			passed = num_traits<float>::isEqual(expected, actual);
			if (passed) actual = noarg1.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) actual = noarg1.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);

			if (passed) actual = noarg2.getRedValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) actual = noarg2.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) actual = noarg2.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);


			Pigment arg1(1.0f, 0.5f, 0.75f);
			Pigment arg2(arg1);	// copy from non-default values
			Pigment arg3;		
			arg3 = arg1;		// assignment

			if (passed) expected = 1.0f;
			if (passed) actual = arg1.getRedValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.5f;
			if (passed) actual = arg1.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.75f;
			if (passed) actual = arg1.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);

			if (passed) expected = 1.0f;
			if (passed) actual = arg2.getRedValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.5f;
			if (passed) actual = arg2.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.75f;
			if (passed) actual = arg2.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);

			if (passed) expected = 1.0f;
			if (passed) actual = arg3.getRedValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.5f;
			if (passed) actual = arg3.getGreenValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);
			if (passed) expected = 0.75f;
			if (passed) actual = arg3.getBlueValue();
			if (passed) passed = num_traits<float>::isEqual(expected, actual);

			utAssert("test_copyAndAssignment", passed);
		}


		void test_EXTRA(void)
		{
		}


		#define EXTRA 0
		void runAllTests(void)
		{
			test_ctor();
			test_getSet();
			test_copyAndAssignment();


			//#if EXTRA
			test_EXTRA();
			//#endif
		}

 };

#endif