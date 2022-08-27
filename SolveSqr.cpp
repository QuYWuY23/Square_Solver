#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>
#include "Solve_Sqr.h"

bool isEqualDouble (double arg1, double arg2)
{
    return fabs (arg1 - arg2) <= Eps;
}

bool isZeroDouble (double arg)
{
    return isEqualDouble (arg, 0);
}

void zeroFix(double *arg)
{
    if (*arg < 0 && isZeroDouble(*arg))
        *arg = 0;

}

void welcomeMessagePrint()
{
        printf (" Write a letter.\n s - solve a quadratic equation.\n"
                                   "t - launch the unit test.\n"
                                   "q - quit.\n");
}

char readUserAnswer()
{
    while (true)
    {
        char read_sym = getchar();
        if (read_sym == 's' || read_sym == 't' || read_sym == 'q')
                return read_sym;
    }
}

void scanSqr (double *coeff_a, double *coeff_b, double *coeff_c)
{
    assert (coeff_a != NULL);
    assert (coeff_b != NULL);
    assert (coeff_c != NULL);

    printf ("Write coefficients for quadratic equation a * x^2 + b * x + c = 0 in form 'a, b, c'\n");

    while (scanf("%lg %lg %lg", coeff_a, coeff_b, coeff_c) != 3)
    {
        clearBuffer();

        printf ("Error,try again to write coefficients a, b, c.\n");
    }
 }

void clearBuffer()
{
    while (getchar() != '\n')
        continue;
}

int solveSqrCase (double coeff_a, double coeff_b, double coeff_c, double *root1, double *root2)
{
    assert (root1 != NULL);
    assert (root2 != NULL);

    if (isZeroDouble(coeff_a))
        return solveLinCase (coeff_b, coeff_c, root1);

    double D = coeff_b * coeff_b - 4 * coeff_a * coeff_c;
    double root_of_D = sqrt(D);

    if (isZeroDouble(D))
    {

        *root1 = - coeff_b / (2 * coeff_a);
        zeroFix(root1);
        return ONE_ROOT;

    }

    if (D > 0)
    {

        *root1 = (- coeff_b + root_of_D) / (2 * coeff_a);
        *root2 = (- coeff_b - root_of_D) / (2 * coeff_a);
        zeroFix(root1);
        zeroFix(root2);
        return TWO_ROOTS;

    }

    return NO_ROOTS;
}

int solveLinCase (double coeff_k, double coeff_b, double *root1)
{
    assert(root1 != NULL);

    if (isZeroDouble(coeff_k))
    {

        if (isZeroDouble(coeff_b))
            return INF_ROOTS;
        else
            return NO_ROOTS;

    }

    *root1 = - coeff_b / coeff_k;
    zeroFix(root1);
    return 1;
}

void printRoots (int num_of_roots, double root1, double root2)
{
    switch (num_of_roots)
    {
        case NO_ROOTS:

            printf ("NO ROOTS\n\n");
            break;

        case INF_ROOTS:

            printf ("ANY NUMBER\n\n");
            break;

        case ONE_ROOT:

            printf ("ONE_ROOT: The root is %lg\n\n",root1);
            break;

        case TWO_ROOTS:

            printf ("TWO_ROOTS: 1st root is %lg\n"
                    "           2nd root is %lg\n\n",root1,root2);
            break;

        default:

            printf ("Error: unexpected amount of roots in print_roots()\n\n");
            break;
     }
}

