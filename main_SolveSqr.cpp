#include <ctype.h>
#include <stdio.h>
#include "Solve_Sqr.h"
#include "Solve_Sqr_unitTesting.h"

int main()
{
    bool running = true;
    while(running)
    {
        int num_of_roots = 0;
        char      letter = 0;
        double   coeff_a = 0.0;
        double   coeff_b = 0.0;
        double   coeff_c = 0.0;
        double     root1 = 0.0;
        double     root2 = 0.0;

        welcomeMessagePrint();
        letter = tolower (readUserAnswer());

        switch(letter)
        {
            case 's':

                scanSqr(&coeff_a, &coeff_b, &coeff_c);
                num_of_roots = solveSqrCase(coeff_a, coeff_b, coeff_c, &root1, &root2);
                printRoots(num_of_roots, root1, root2);
                break;

            case 't':

                unitTesting();
                break;

            case 'q':

                running = false;
                break;

            default:

                printf(" Error, incorrect letter,try again.");
                clearBuffer();
                break;
        }
    }
    return 0;
}

