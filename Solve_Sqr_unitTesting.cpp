#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "Solve_Sqr.h"
#include "Solve_Sqr_unitTesting.h"

#if 0
struct Test_Data {
    double  coeff_a = 0;
    double  coeff_b = 0;
    double  coeff_c = 0;
    double    root1 = 0;
    double    root2 = 0;
    int n_roots = NO_ROOTS;
};
#endif



void unitTesting()
{

    double coeff_a = 0.0;
    double coeff_b = 0.0;
    double coeff_c = 0.0;
    double x1_test = NAN;
    double x2_test = NAN;
    double x1_answ = NAN;
    double x2_answ = NAN;

    const int amount_of_tests = sizeof(checking_list) / sizeof(Test_Data);

    for (int cur_test = 1; cur_test < amount_of_tests + 1; ++cur_test)
    {

              coeff_a = checking_list[cur_test].coeff_a;
              coeff_b = checking_list[cur_test].coeff_b;
              coeff_c = checking_list[cur_test].coeff_c;
              x1_answ = checking_list[cur_test].root1;
              x2_answ = checking_list[cur_test].root2;


        int test_n_roots = solveSqrCase (coeff_a, coeff_b, coeff_c, &x1_test, &x2_test);

        unitTestWriteRes (test_n_roots, x1_test, x2_test, cur_test);
    }
}

void unitTestWriteRes(int test_n_roots, double x1_test, double x2_test, int test_number)
{

    double x1_answ = checking_list[test_number].root1;
    double x2_answ = checking_list[test_number].root2;
    int    n_roots = checking_list[test_number].n_roots;

    printf ("Test %d Case:\n", test_number);
    printf ("Expected: %d roots", n_roots);

    if (test_n_roots == checking_list[test_number].n_roots)
    {
        switch (test_n_roots)
        {
            case NO_ROOTS:

                printf ("Test %d has completed succesfully.\n\n", test_number);
                break;

            case INF_ROOTS:

                printf ("Test %d has completed succesfully.\n\n", test_number);
                break;

            case ONE_ROOT:

                if(isEqualDouble (x1_test, x1_answ))
                    printf ("Test %d has completed succesfully.\n\n", test_number);
                else
                    printf ("Test %d has an error! Program returns %lg, %lg.\n\n", test_number, x1_test, x2_test);
                break;

            case TWO_ROOTS:

                if ( ( isEqualDouble(x1_test, x1_answ) && isEqualDouble(x2_test, x2_answ) )
                ||   ( isEqualDouble(x1_test, x2_answ) && isEqualDouble(x2_test, x1_answ) ))
                    printf ("Test %d has completed succesfully.\n\n", test_number);
                else
                    printf ("Test %d has an error! Program returns %lg, %lg.\n\n", test_number, x1_test, x2_test);
                break;

            default:

                printf ("Error: unexpected amount of roots in unitTestWriteRes");
                break;
            }
        }
        else
        {
            switch(test_n_roots)
            {
                case INF_ROOTS:

                    printf ("Test %d has an error! Program returns INF ROOTS.\n\n", test_number);
                    break;

                case NO_ROOTS:

                    printf ("Test %d has an error! Program returns NO ROOTS.\n\n", test_number);                        //// under: remove --> print_root_case(nRoots)
                    break;

                case ONE_ROOT:

                    printf ("Test %d has an error! Program returns ONE ROOT.\n\n", test_number);
                    break;

                case TWO_ROOTS:

                    printf ("Test %d has an error! Program returns TWO ROOTS.\n\n", test_number);                                    // switch(nRoots)
                    break;

                default:

                    printf ("Error: unexpected amount of roots in unitTestWriteRes");
                    break;
            }
        }
}

