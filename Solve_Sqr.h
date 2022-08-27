// 0) correct all замечания
// 1) correct name .h / .cpp  //ready
// 2) delete files  // ready
// 3) make files unit_tests.cpp / .h
// 4) NAMING NAMINGMNMINIANIFNIANFINF1!!!!!!!!!!!!!!

// последний) try doxygen

#ifndef SOLVE_SQR_H
#define SOLVE_SQR_H
#include <math.h>

///Used to compare double numbers.
const double Eps = 10E-8;

///Using to store numbers of roots of quadratic equation.
enum  amountOfRoots {
     NO_ROOTS  =   0,
     INF_ROOTS =   3,
     ONE_ROOT  =   1,
     TWO_ROOTS =   2
};

///Check if the double value is 0.
///@param[in] a
///\return True if argument is 0 , false if not.
bool isZeroDouble(double arg);

///Check if two double values are equal.
///@param[in] frst_arg      first argument
///@param[in] scnd_arg      second argument
///\return True if first argument and second argument are equal, false if not.
bool isEqualDouble(double frst_arg, double scnd_arg);

///Suggest to user to make a choice among unit testing, solving quadratic equation and exit.
void welcomeMessagePrint();

/// Scan coefficients,using multiuser input.
/// @param[out] coeff_a   coefficient of quadratic equation
/// @param[out] coeff_b   coefficient of quadratic equation
/// @param[out] coeff_c   coefficient of quadratic equation
void scanSqr(double *coeff_a, double *coeff_b, double *coeff_c);

/// Clear stdin input buffer.
void clearBuffer();

///Read one of 3 letters s, t, q.
///\return one letter.
char readUserAnswer();

/// Count number of roots in quadratic equation .
/// @param[in]  coeff_a   coefficient
/// @param[in]  coeff_b   coefficient
/// @param[in]  coeff_c   coefficient
/// @param[out] root1     1st root
/// @param[out] root2     2nd root
///\return number of roots.
int solveSqrCase(double coeff_a, double coeff_b, double coeff_c, double *root1, double *root2);

/// Solves the linear equation.
/// @param[in]  coeff_k      coefficient at x
/// @param[in]  coeff_b      free coefficient
/// @param[out] root1        the root
///\return 1 - number of roots.
int solveLinCase(double coeff_k, double coeff_b, double *root1);

/// Print roots.
/// @param[in]  num_of_roots    number of roots
/// @param[in]  root1           1st root
/// @param[in]  root2           2nd root
void printRoots(int num_of_roots, double root1, double root2);

#endif
