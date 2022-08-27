#ifndef SOLVE_SQR_UNIT_TESTING_H
#define SOLVE_SQR_UNIT_TESTING_H
#include <math.h>

///Using to store parametres and answers of quadratic equation.
struct Test_Data    ///
    {
    double  coeff_a = 0;
    double  coeff_b = 0;
    double  coeff_c = 0;
    double    root1 = 0;
    double    root2 = 0;
    enum amountOfRoots n_roots = INF_ROOTS;
    };

const struct Test_Data checking_list[] =
    {
    (struct Test_Data) {   0,   0,   0,    0,   0,  NO_ROOTS },
        {   0,   0,   6,  NAN, NAN,  NO_ROOTS },
        {   0,   0,   0,  NAN, NAN, INF_ROOTS },
        {   1,   2,   1,   -1, NAN,  ONE_ROOT },
        {   1,  -2, -15,   -3,   5, TWO_ROOTS }
    };
/// \brief Function to test function of quadratic equation.
void unitTesting();

/// Print result of one unit test.
/// @param[in] test_num_of_roots      number of roots which give unit test
/// @param[in] x1_test                1st root which returns unit test
/// @param[in] x2_test                2nd root which returns unit test
/// @param[in] test_number            test number
void unitTestWriteRes (int test_num_of_roots, double x1_test, double x2_test, int test_number);

#endif

