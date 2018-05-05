//
//  main.cpp
//  nn1338_hw3_q3
//
//  Created by NomNomNam on 5/2/18.
//  Copyright © 2018 NamHNguyen NYU Tandon School of Engineering Bridge 2018 Program. All rights reserved.
//

/*
 
 Write a program that does the following:
 • Ask user to input three Real numbers a, b and c. They represent the parameters of a
 quadratic equation 𝑎𝑥# + 𝑏𝑥 + 𝑐 = 0
 • Classify to one of the following:
    - ’Infinite number of solutions’ (for example, 0𝑥# + 0𝑥 + 0 = 0 has infinite number of solutions)
    - ’No solution’ (for example, 0𝑥# + 0𝑥 + 4 = 0 has no solution)
    - ’No real solution’ (for example, 𝑥# + 4 = 0 has no real solutions)
    - ’One real solution’
    - ’Two real solutions’
 • In cases there are 1 or 2 real solutions, also print the solutions.
 
 Notes:
 1. If 𝑎 ≠ 0 and there are real solutions to the equation, you can get these solutions using
 the following formula: *quadratic formula*
 
 The number of solutions depends on whether (b2 -4ac) is positive, zero, or negative.
 
 2. In order to calculate the square root of a number (of type double), you should call the sqrt function, located in the cmath library.
 
    Follow the syntax as demonstrated in the code below:
    #include <iostream>
    #include <cmath>
    using namespace std;
 
    int main() {
        double x = 2.0;
        double sqrtResult; sqrtResult = sqrt(x);
        cout<<sqrtResult<<endl; return 0;
    }
 
    Note that you first need to include the cmath library, and then you can call the sqrt function, passing the argument that you want to calculate the square root of, enclosed in parentheses.
 
 Your program should interact with the user exactly as it shows in the following example:
 Please enter value of a: 1
 Please enter value of b: 4
 Please enter value of c: 4
 This equation has a single real solution x=-2.0
 
 */

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int a, b, c;
    string predictedNumOfSolution;
    double quadraticRoot;
    double addQuadraticSolution, subQuadraticSolution;
    
    cout<<"Please enter value of a: ";
    cin>>a;
    
    cout<<"Please enter value of b: ";
    cin>>b;
    
    cout<<"Please enter value of c: ";
    cin>>c;
    
    // Quadratic math formula
    quadraticRoot = (b*b - 4*a*c);
    addQuadraticSolution = (-b + sqrt(quadraticRoot)) / (2*a);
    subQuadraticSolution = (-b - sqrt(quadraticRoot)) / (2*a);
    
    // Case for infinite of solutions
    if (a == 0 && b == 0 && c == 0)
        predictedNumOfSolution = "infinite number of solutions";
    // Case for no solutions
    else if (a == 0 && b == 0 && c != 0)
        predictedNumOfSolution = "no solution";
    // Case if there are values for a and implicit that b or c is either 0 or have values
    // if a is 0 then there are infinite # of solutions based on the quadratic formula
    else if (a != 0) {
        // Case for two real solutions if b^2 - 4ac > 0
        if (quadraticRoot > 0) {
            predictedNumOfSolution = "two real solutions";
            cout<<"This equation has "<<predictedNumOfSolution<<" x="<<subQuadraticSolution<<", x="<<addQuadraticSolution<<endl;
        // Case for one real solution if b^2 - 4ac = 0
        } else if (quadraticRoot == 0) {
            predictedNumOfSolution = "one real solution";
            cout<<"This equation has "<<predictedNumOfSolution<<" x="<<addQuadraticSolution<<endl;
        // Case for no real solution if b^2 - 4ac is < 0 because you cannot square root a negative number
        // to get a real number
        } else
            predictedNumOfSolution = "no real solution";
    } else
        // Case if a == 0 and b or c is either 0 or have values
        predictedNumOfSolution = "infinite number of solutions";
    
    if (predictedNumOfSolution == "infinite number of solutions" ||
        predictedNumOfSolution == "no solution" ||
        predictedNumOfSolution == "no real solution")
        cout<<"This equation has "<<predictedNumOfSolution<<endl;
    
    return 0;
}
