/**
*
* Solution to course project # 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Elis Shukri
* @idnumber 8MI0600194
* @compiler VC
*
* <main functionality>
*
*/

#include <iostream>
#include <cmath>

const double CHECK_VALUE1 = -0.0000001;
const double CHECK_VALUE2 = 0.0000001;
const int MAX_SIZE = 100;
const char FIRST_CHOICE = '1';
const char SECOND_CHOICE = '2';
const char THIRD_CHOICE = 'a';
const char FOURTH_CHOICE = 'b';
const char FIFTH_CHOICE = 'c';
const char SIXTH_CHOICE = 'd';
const char SEVENTH_CHOICE = 'e';
const char EIGHTH_CHOICE = 'f';
const char NINTH_CHOICE = 'g';
const char TENTH_CHOICE = 'h';
const char ELEVENTH_CHOICE = 'i';
const char TWELFTH_CHOICE = 'j';
const char THIRTEENTH_CHOICE = 'k';


bool doesPointLieOnLine(double x, double y, double a, double b, double c)
{
    double check = a * x + b * y + c;     
    if(check > CHECK_VALUE1 && check < CHECK_VALUE2)
    {
        return true;
    }
    else { return false; }
}

void printLine(double a, double b, double c)
{
    if (a == -1.0) {                        // We check the coeficients of the line.
        std::cout << "-x ";
    }
    else if (a == 1.0) {
        std::cout << "x ";
    }
    else if (a != 0.0) { std::cout << a << "x "; }

    if (b == -1.0) {
        std::cout << "- y ";
    }
    else if (b == 1.0) {
        std::cout << "+ y ";
    }
    else if (b > CHECK_VALUE2 && b != 1.0) {
        std::cout << "+ " << b << "y ";
    }
    else if (b < CHECK_VALUE1) { 
        std::cout << "- " << -b << "y ";
    }

    if (c > CHECK_VALUE2) {
        std::cout << "+ " << c;
    }
    else if (c < CHECK_VALUE1) { 
        std::cout << "- " << -c;
    }
    std::cout << " = 0";
}

void printLineParallelToLineThroughPoint(double x, double y, double a, double b, double c)
{
    // We can get parallel line by the equation: x - pointX / -b = y - pointY / a
    // In this case x and y are point coordinates(pointX and pointY), a, b and c are line coeficients.

    double newC = a * (-x) + b * (-y); 
    printLine(a, b, newC);    
}

void printPerpendicularLineToLine(double x, double y, double a, double b, double c)
{
    // We can get perpendicular line by the equation: x - pointX / a = y - pointY / b
    // In this case x and y are point coordinates(pointX and pointY), a, b and c are line coeficients.

    double newA = -b;                 
    double newB = a;            
    double newC = -a * y + b * x;
    printLine(newA, newB, newC);
}

void findCommonPoint(double a1, double b1, double c1, double a2, double b2, double c2, double* x, double* y)
{
    // We get the common point's coordinates by getting x and y from the equations of the lines.

    *y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1); 
    *x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1); 
}

void findLineThroughTwoPoints(double x1, double x2, double y1, double y2, double* a, double* b, double* c)
{
    
    *a = y1 - y2;
    *b = x2 - x1;             // We get the line by using the formula: x - x1 / x2 - x1 = y - y1 / y2 - y1
    *c = x1 * y2 - x2 * y1;
}

void findMiddle(double x1, double x2, double y1, double y2, double* newX, double* newY)
{
    *newX = (x2 + x1) / 2;
    *newY = (y2 + y1) / 2;
}

double powNumber(double number, int power)
{
    double result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

bool compareDoubleNumbers(double num1, double num2)
{
    double difference = num1 - num2;
    double absDifference = difference > 0 ? difference : -difference;

    if (absDifference < CHECK_VALUE2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pointLiesOnParabola(double x, double y, double a, double b, double c)
{
    double y1 = a * powNumber(x, 2) + b * x + c;
    
    if (compareDoubleNumbers(y1, y) == 1)
    {
        return true;
    }
    else { return false; }
}

void findTangentThroughPointOnParabola(double x, double y, double a, double b, double c)
{
    
    double newA = 2 * a * x + b;
    double newB = -1;
    double newC = -a * powNumber(x, 2) + c;  // Here we use the formula: f'(x0)(x - x0) + f(x0), x0 - coordinate of the point.
    printLine(newA, newB, newC);
}

void findTangentThroughPointNotOnParabola(double x, double y, double a, double b, double c)
{
    double quadraticA = - a;        // We use the formula: y = f'(x0)(x - x0) + f(x0), x and y - point's coordinates.
    double quadraticB = 2 * a * x;
    double quadraticC = b * x + c - y;
    double discriminant = powNumber(quadraticB, 2) - 4 * quadraticA * quadraticC;
    
    if(discriminant < CHECK_VALUE1)
    {
        std::cout << "There is not a tangent";
    }
    else if (discriminant > CHECK_VALUE1 && discriminant < CHECK_VALUE2)
    {
        double x1 = -quadraticB / 2 * quadraticA;   // We use the formula : y = f'(x0)(x - x0) + f(x0), x0 = x1
        double newA = 2 * x1 * a + b;
        double newB = -1;
        double newC = (2 * x1 * a + b) * (- x1);
        printLine(newA, newB, newC);
    }
    else
    {
        double sqrtDiscriminant = sqrt(discriminant);
        
        double x1 = (- quadraticB + sqrtDiscriminant) / 2 * quadraticA;
        double x2 = (- quadraticB - sqrtDiscriminant) / 2 * quadraticA;
        
        double newA1 = 2 * a * x1 + b;
        double newB1 = -1;
        double newC1 = (2 * x1 * a + b) * (- x1) + a * powNumber(x1, 2) + b * x1 + c;

        double newA2 = 2 * a * x2 + b;
        double newB2 = -1;
        double newC2 = (2 * x2 * a + b) * (- x2) + a * powNumber(x2, 2) + b * x2 + c;
        printLine(newA1, newB1, newC1);
        std::cout << std::endl;
        printLine(newA2, newB2, newC2);
    }
}

void findCommonPointsOfLineAndParabola(double a1, double b1, double c1, double a2, double b2, double c2)
{
    // We solve the system: y = a1x^2 + b1x + c1, a2x + b2y + c2 = 0

    double discriminant = powNumber(a2 + b1 * b2, 2) - 4 * a1 * b2 * (b2 * c1 + c2);
    if (discriminant < CHECK_VALUE1) { std::cout << "There is no common point"; }    // a1, b1, c1 - parabola a2, b2, c2 - line
    else if (discriminant > CHECK_VALUE1 && discriminant < CHECK_VALUE2)
    {
        double x = (-a2 - b1 * b2) / 2 * a1 * b2;
        double y = a1 * powNumber(x, 2) + b1 * x + c1;
        std::cout << "(" << x << ";" << y << ")";
    }
    else
    {
        double x1 = (-a2 - b1 * b2 + sqrt(discriminant)) / 2 * a1 * b2;
        double x2 = (-a2 - b1 * b2 - sqrt(discriminant)) / 2 * a1 * b2;
        double y1 = a1 * powNumber(x1, 2) + b1 * x1 + c1;
        double y2 = a1 * powNumber(x2, 2) + b1 * x2 + c1;
        std::cout << "(" << x1 << ";" << y1 << ")" << " " << "(" << x2 << ";" << y2 << ")";
    }

}

bool areTwoLinesParallel(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double newA1, newB1, newA2, newB2 = 0.0;
    if (b1 == 0 && b2 != 0 || b1 != 0 && b2 == 0)
    {
        return false;
    }
    if (b1 == 0 && b2 == 0)
    {
        return true;
    }
    newA1 = -a1 / b1;
    newB1 = -c1 / b1;       // We make the lines in y = kx + b
    newA2 = -a2 / b2;
    newB2 = -c2 / b2;

    if (compareDoubleNumbers(newA1, newA2) == 1 && compareDoubleNumbers(newB1, newB2) == 0)
    {
        return true;
    }
    else { return false; }
}

double findDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    double x = x2 - x1;
    double y = y2 - y1;
    double distance = x * x + y * y;
    return distance;
}

bool isAngleRight(double a1, double b1, double a2, double b2)
{
    double result = a1 * a2 + b1 * b2;
    return (result > CHECK_VALUE1 && result < CHECK_VALUE2) ? true : false;
}

bool checkRectangularTrapezoid(double a1, double b1, double a2, double b2, double a3, double b3, double a4, double b4)
{
    int firstCheck = isAngleRight(a1, b1, a3, b3);
    int secondCheck = isAngleRight(a1, b1, a4, b4);
    int thirdCheck = isAngleRight(a2, b2, a3, b3);
    int fourthCheck = isAngleRight(a2, b2, a4, b4);
    int sum = firstCheck + secondCheck + thirdCheck + fourthCheck;
    return(sum == 2) ? true : false;
}

bool checkLeg(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    double x, y = 0.0;
    findCommonPoint(a3, b3, c3, a4, b4, c4, &x, &y);       // Legs have common point inside or outside??
    if (a1 < CHECK_VALUE1) 
    { 
        a1 = 0 - a1;
        b1 = 0 - b1;
        c1 = 0 - c1;
    }
    if (a2 < CHECK_VALUE1)
    {
        a2 = 0 - a2;
        b2 = 0 - b2;
        c2 = 0 - c2;
    }
    
    double firstCheck = a1 * x + b1 * y + c1;
    double secondCheck = a2 * x + b2 * y + c2;
    if((firstCheck < CHECK_VALUE1 && secondCheck < CHECK_VALUE1) || (firstCheck > CHECK_VALUE2 && secondCheck > CHECK_VALUE2))
    {
        return true;
    }
    else { 
        return false; 
    }
}

bool IsoscelesTrap(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    double x13, y13, x14, y14, x23, y23, x24, y24 = 0.0;
    findCommonPoint(a1, b1, c1, a3, b3, c3, &x13, &y13);
    findCommonPoint(a1, b1, c1, a4, b4, c4, &x14, &y14);
    findCommonPoint(a2, b2, c2, a3, b3, c3, &x23, &y23);
    findCommonPoint(a2, b2, c2, a4, b4, c4, &x24, &y24);
    
    double distance1 = findDistanceBetweenTwoPoints(x13, y13, x23, y23);
    double distance2 = findDistanceBetweenTwoPoints(x14, y14, x24, y24);
    
    int leg = checkLeg(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);

    return (compareDoubleNumbers(distance1, distance2) == 1 && leg == 1) ? true : false;
}

void checkTrap(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    if (checkRectangularTrapezoid(a1, b1, a2, b2, a3, b3, a4, b4) == 1)
    {
        std::cout << "Rectangular Trapezoid";
    }
    else if (IsoscelesTrap(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4) == 1)
    {
        std::cout << "Isosceles Trapezoid";
    }
    else 
    { 
        if (checkLeg(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4) == 1)
        {
            std::cout << "Trapezoid";
        }
        else { std::cout << "Not a quadrilateral"; }
    }
}

void checkFig2(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    double x1, y1, x2, y2, x3, y3 = 0.0;
    findCommonPoint(a1, b1, c1, a3, b3, c3, &x1, &y1);
    findCommonPoint(a1, b1, c1, a4, b4, c4, &x2, &y2);
    findCommonPoint(a2, b2, c2, a4, b4, c4, &x3, &y3);

    double distance1 = findDistanceBetweenTwoPoints(x1, y1, x2, y2);
    double distance2 = findDistanceBetweenTwoPoints(x2, y2, x3, y3);
    
    int areSidesEqual = compareDoubleNumbers(distance1, distance2);
    double angle = a1 * a3 + b1 * b3;

    if (angle > CHECK_VALUE1 && angle < CHECK_VALUE2 && areSidesEqual == 0) { 
        std::cout << "Rectangle"; 
    }
    else if (angle < CHECK_VALUE1 || angle > CHECK_VALUE2 && areSidesEqual == 1) { 
        std::cout << "Rhombus"; 
    }
    else if (angle > CHECK_VALUE1 && angle < CHECK_VALUE2 && areSidesEqual == 1) { 
        std::cout << "Square"; 
    }
    else { 
        std::cout << "Parallelogram"; 
    }
}

bool doTwoLinesMatch(double a1, double b1, double c1, double a2, double b2, double c2)
{
    if(a1 == a2 && b1 == b2 && c1 == c2)
    {
        return true;
    }
    else if (a1 == 0 - a2 && b1 == 0 - b2 && c1 == 0 - c2)
    {
        return true;
    }
    else { return false; }
}

bool commonPointThreeLines(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    double x, y = 0.0;
    if (areTwoLinesParallel(a1, b1, c1, a2, b2, c2) == 0 && doTwoLinesMatch(a1, b1, c1, a2, b2, c2) == 0)
    {
        findCommonPoint(a1, b1, c1, a2, b2, c2, &x, &y);
        double checkThirdLine = a3 * x + b3 * y + c3;
        double checkFourthLine = a4 * x + b4 * y + c4;
        if (checkThirdLine < CHECK_VALUE2 && checkThirdLine > CHECK_VALUE1)
        {
            return true;
        }
        else if (checkFourthLine < CHECK_VALUE2 && checkFourthLine > CHECK_VALUE1)
        {
            return true;
        }
        else { return false; }
    }
    else { return false; }
}

void checkFig(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    int firstCheck = areTwoLinesParallel(a1, b1, c1, a2, b2, c2);
    int secondCheck = areTwoLinesParallel(a1, b1, c1, a3, b3, c3);
    int thirdCheck = areTwoLinesParallel(a1, b1, c1, a4, b4, c4);
    int fourthCheck = areTwoLinesParallel(a2, b2, c2, a3, b3, c3);
    int fifthCheck = areTwoLinesParallel(a2, b2, c2, a4, b4, c4);
    int sixthCheck = areTwoLinesParallel(a3, b3, c3, a4, b4, c4);

    int firstPoint = commonPointThreeLines(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);
    int secondPoint = commonPointThreeLines(a1, b1, c1, a3, b3, c3, a2, b2, c2, a4, b4, c4);
    int thirdPoint = commonPointThreeLines(a1, b1, c1, a4, b4, c4, a2, b2, c2, a3, b3, c3);
    int fourthPoint = commonPointThreeLines(a2, b2, c2, a3, b3, c3, a1, b1, c1, a4, b4, c4);
    int fifthPoint = commonPointThreeLines(a2, b2, c2, a4, b4, c4, a1, b1, c1, a3, b3, c3);
    int sixthPoint = commonPointThreeLines(a3, b3, c3, a4, b4, c4, a1, b1, c1, a2, b2, c2);

    int firstMatch = doTwoLinesMatch(a1, b1, c1, a2, b2, c2);
    int secondMatch = doTwoLinesMatch(a1, b1, c1, a3, b3, c3);
    int thirdMatch = doTwoLinesMatch(a1, b1, c1, a4, b4, c4);
    int fourthMatch = doTwoLinesMatch(a2, b2, c2, a3, b3, c3);
    int fifthMatch = doTwoLinesMatch(a2, b2, c2, a4, b4, c4);
    int sixthMatch = doTwoLinesMatch(a3, b3, c3, a4, b4, c4);

    int sum = firstCheck + secondCheck + thirdCheck + fourthCheck + fifthCheck + sixthCheck;
    int sum2 = firstPoint + secondPoint + thirdPoint + fourthPoint + fifthPoint + sixthPoint;
    int sum3 = firstMatch + secondMatch + thirdMatch + fourthMatch + fifthMatch + sixthMatch;

    if (sum >= 3 || sum2 >= 3 || sum3 >= 1) { 
        std::cout << "Not a quadrilateral"; 
    }
    else if (sum == 0 && sum2 == 0 && sum3 == 0) { 
        std::cout << "Arbitrary quadrilateral"; 
    }
    else
    {
        if (firstCheck == 1)
        {
            if (sixthCheck == 1) { 
                checkFig2(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);
            }
            else { 
                checkTrap(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);
            }
        }
        else if (secondCheck == 1)
        {
            if (fifthCheck == 1) {
                checkFig2(a1, b1, c1, a3, b3, c3, a2, b2, c2, a4, b4, c4);
            }
            else {checkTrap(a1, b1, c1, a3, b3, c3, a2, b2, c2, a4, b4, c4);}
        }
        else if (thirdCheck == 1)
        {
            if (fourthCheck == 1) {
                checkFig2(a1, b1, c1, a4, b4, c4, a2, b2, c2, a3, b3, c3);
            }
            else { 
                checkTrap(a1, b1, c1, a4, b4, c4, a2, b2, c2, a3, b3, c3);
            }
        }
        else if (sixthCheck == 1 && firstCheck == 0) { 
            checkTrap(a3, b3, c3, a4, b4, c4, a1, b1, c1, a2, b2, c2); 
        }
        else if (fifthCheck == 1 && secondCheck == 0) {
            checkTrap(a2, b2, c2, a4, b4, c4, a1, b1, c1, a3, b3, c3); 
        }
        else if (fourthCheck == 1 && thirdCheck == 0) { 
            checkTrap(a2, b2, c2, a3, b3, c3, a1, b1, c1, a4, b4, c4); 
        }
    }
}

bool isValidName(const char* name)
{
    size_t index = 0;
    while (name[index] != '\0')
    {
        if (name[index] < 'a' || name[index] > 'z')
        {
            if (name[index] < 'A' || name[index] > 'Z')
            {
                if (name[index] - '0' < 0 || name[index] - '0' > 9)
                {
                    if (name[index] != '_')
                        return false;
                }
            }
        }
        index++;
    }
    return true;
}

void checkName(char* name)
{
    while (isValidName(name) == 0)
    {
        std::cout << "Please, enter a name that includes Latin letters, Arabic numbers or '_'." << std::endl;
        std::cin >> name;
    }
    
}

void actionsPointAndLine(char firstChoiceNumber, char secondChoiceNumber)
{
    double x, y = 0.0;
    double a, b, c = 0.0;
    char pointName[MAX_SIZE] = "\0";
    char lineName[MAX_SIZE] = "\0";

    if (firstChoiceNumber == SECOND_CHOICE)
    {
        std::cout << "Enter the name of the point: ";
        std::cin >> pointName;
        checkName(pointName);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the line: ";
        std::cin >> lineName;
        checkName(lineName);
        std::cin.ignore(MAX_SIZE, '\n');
    }

    if (secondChoiceNumber == THIRD_CHOICE)
    {
        std::cout << "Enter point's coordinates: ";
        std::cin >> x >> y;
        std::cout << "Enter the coefficients of the line: ";
        std::cin >> a >> b >> c;
        if (doesPointLieOnLine(x, y, a, b, c) == 1) {
            std::cout << "Yes, the point " << pointName << " lies on the line " << lineName;
        }
        else {
            std::cout << "The point does not lie on the line.";
        }
    }
    else if (secondChoiceNumber == FOURTH_CHOICE)
    {
        std::cout << "Enter point's coordinates: ";
        std::cin >> x >> y;
        std::cout << "Enter the coefficients of the line: ";
        std::cin >> a >> b >> c;
        std::cout << "The equation of the line parallel to line " << lineName << " through point " << pointName << " is: "; 
        printLineParallelToLineThroughPoint(x, y, a, b, c);
    }
    else if (secondChoiceNumber == FIFTH_CHOICE)
    {
        std::cout << "Enter point's coordinates: ";
        std::cin >> x >> y;
        std::cout << "Enter the coefficients of the line: ";
        std::cin >> a >> b >> c;

        if (doesPointLieOnLine(x, y, a, b, c) == 1) {
            std::cout << "The equation of the line perpendicular to line " << lineName << " through point " << pointName << " is: ";
            printPerpendicularLineToLine(x, y, a, b, c);
        }
        else {
            std::cout << "The point is not on the line." << std::endl;
            std::cout << "But the equation of the line perpendicular to line " << lineName << " through your point " << pointName << " is: " << std::endl;
            printPerpendicularLineToLine(x, y, a, b, c);
        }
    }
}

void actionsTwoLines(char firstChoiceNumber, char secondChoiceNumber)
{
    double a1, b1, c1 = 0.0;
    double a2, b2, c2 = 0.0;
    double x, y = 0.0;
    char line1Name[MAX_SIZE] = "\0";
    char line2Name[MAX_SIZE] = "\0";

    if (firstChoiceNumber == SECOND_CHOICE)
    {
        std::cout << "Enter the name of the first line: ";
        std::cin >> line1Name;
        checkName(line1Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the second line: ";
        std::cin >> line2Name;
        checkName(line2Name);
        std::cin.ignore(MAX_SIZE, '\n');
    }
    if (secondChoiceNumber == SIXTH_CHOICE)
    {
        std::cout << "Enter the coeficients of the first line: ";
        std::cin >> a1 >> b1 >> c1;
        std::cout << "Enter the coeficients of the second line: ";
        std::cin >> a2 >> b2 >> c2;

        if (areTwoLinesParallel(a1, b1, c1, a2, b2, c2) == 0 && doTwoLinesMatch(a1, b1, c1, a2, b2, c2) == 0)
        {
            findCommonPoint(a1, b1, c1, a2, b2, c2, &x, &y);
            std::cout << "The common point of the first line " << line1Name << " and the second line " << 
                line2Name << " is: (" << x << ";" << y << ")";
        }
        else if (areTwoLinesParallel(a1, b1, c1, a2, b2, c2) == 1)
        {
            std::cout << "The two lines " << line1Name << " " << line2Name << " are parallel.";
        }
        else if (doTwoLinesMatch(a1, b1, c1, a2, b2, c2) == 1)
        {
            std::cout << "The two lines " << line1Name << " " << line2Name << " match.";
        }
    }
}

void printHeights(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a, b, c = 0.0;
    findLineThroughTwoPoints(x1, x2, y1, y2, &a, &b, &c);
    printPerpendicularLineToLine(x3, y3, a, b, c);
}

void printMedians(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double newX, newY, a, b, c = 0.0;
    findMiddle(x1, x2, y1, y2, &newX, &newY);
    findLineThroughTwoPoints(x3, newX, y3, newY, &a, &b, &c);
    printLine(a, b, c);
}

void printBisectors(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double newX, newY, a, b, c = 0.0;
    findMiddle(x1, x2, y1, y2, &newX, &newY);
    findLineThroughTwoPoints(x1, x2, y1, y2, &a, &b, &c);
    printPerpendicularLineToLine(newX, newY, a, b, c);
}

void actionsWithTriangle(char firstChoiceNumber, char secondChoiceNumber)
{
    double x1, x2, x3, y1, y2, y3 = 0.0;
    char point1Name[MAX_SIZE] = "\0";
    char point2Name[MAX_SIZE] = "\0";
    char point3Name[MAX_SIZE] = "\0";

    if (firstChoiceNumber == SECOND_CHOICE)
    {
        std::cout << "Enter the name of the first point: ";
        std::cin >> point1Name;
        checkName(point1Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the second point: ";
        std::cin >> point2Name;
        checkName(point2Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the third point: ";
        std::cin >> point3Name;
        checkName(point3Name);
        std::cin.ignore(MAX_SIZE, '\n');
    }

    if (secondChoiceNumber == SEVENTH_CHOICE)
    {
        
        std::cout << "Enter the coordinates of the first point: ";
        std::cin >> x1 >> y1;
        std::cout << "Enter the coordinates of the second point: ";
        std::cin >> x2 >> y2;
        std::cout << "Enter the coordinates of the third point: ";
        std::cin >> x3 >> y3;
        
        std::cout << "The height through the first point " << point1Name << " is: ";
        printHeights(x2, y2, x3, y3, x1, y1); 
        std::cout << std::endl << "The height through the second point " << point2Name << " is: ";
        printHeights(x1, y1, x3, y3, x2, y2);
        std::cout << std::endl << "The height through the third point " << point3Name << " is: ";
        printHeights(x1, y1, x2, y2, x3, y3);

        std::cout << std::endl << "The median through the first point " << point1Name << " is: ";
        printMedians(x2, y2, x3, y3, x1, y1);
        std::cout << std::endl << "The median through the second point " << point2Name << " is: ";
        printMedians(x1, y1, x3, y3, x2, y2);
        std::cout << std::endl << "The median through the third point " << point3Name << " is: ";
        printMedians(x1, y1, x2, y2, x3, y3);

        std::cout << std::endl << "The bisector to the first side " << point2Name << point3Name << " is: ";
        printBisectors(x2, y2, x3, y3, x1, y1);
        std::cout << std::endl << "The bisector to the second side " << point1Name << point3Name << " is: ";
        printBisectors(x1, y1, x3, y3, x2, y2);
        std::cout << std::endl << "The bisector to the third side " << point1Name << point2Name << " is: ";
        printBisectors(x1, y1, x2, y2, x3, y3);
        
    }
}

void actionsWithTriangle2(char firstChoiceNumber, char secondChoiceNumber)
{
    char point1Name[MAX_SIZE] = "\0";
    char point2Name[MAX_SIZE] = "\0";
    char point3Name[MAX_SIZE] = "\0";
    double x1, x2, x3, y1, y2, y3 = 0.0;
    std::cout << "Enter the coordinates of the first point: ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the second point: ";
    std::cin >> x2 >> y2;
    std::cout << "Enter the coordinates of the third point: ";
    std::cin >> x3 >> y3;

    if (firstChoiceNumber == SECOND_CHOICE) {
        std::cout << "Enter the name of the first point: ";
        std::cin >> point1Name;
        checkName(point1Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the second point: ";
        std::cin >> point2Name;
        checkName(point1Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the third point: ";
        std::cin >> point3Name;
        checkName(point3Name);
        std::cin.ignore(MAX_SIZE, '\n');
    }

    if (secondChoiceNumber == EIGHTH_CHOICE) {
        std::cout << "The height through the first point " << point1Name << " is: ";
        printHeights(x2, y2, x3, y3, x1, y1);
        std::cout << std::endl << "The height through the second point " << point2Name << " is: ";
        printHeights(x1, y1, x3, y3, x2, y2);
        std::cout << std::endl << "The height through the third point " << point3Name << " is: ";
        printHeights(x1, y1, x2, y2, x3, y3);
    }
    else if (secondChoiceNumber == NINTH_CHOICE) {

        std::cout << "The median through the first point " << point1Name << " is: ";
        printMedians(x2, y2, x3, y3, x1, y1);
        std::cout << std::endl << "The median through the second point " << point2Name << " is: ";
        printMedians(x1, y1, x3, y3, x2, y2);
        std::cout << std::endl << "The median through the third point " << point3Name << " is: ";
        printMedians(x1, y1, x2, y2, x3, y3);
    }
    else if (secondChoiceNumber == TENTH_CHOICE) {

        std::cout << "The bisector to the first side " << point2Name << point3Name << " is: ";
        printBisectors(x2, y2, x3, y3, x1, y1);
        std::cout << std::endl << "The bisector to the second side " << point1Name << point3Name << " is: ";
        printBisectors(x1, y1, x3, y3, x2, y2);
        std::cout << std::endl << "The bisector to the third side " << point1Name << point2Name << " is: ";
        printBisectors(x1, y1, x2, y2, x3, y3);
    }
}

void actionsWithParabolaAndPoint(char firstChoiceNumber, char secondChoiceNumber)
{
    double x, y, a, b, c = 0.0;
    char parabolaName[MAX_SIZE] = "\0";
    char pointName[MAX_SIZE] = "\0";

    if (firstChoiceNumber == SECOND_CHOICE)
    {
        std::cout << "Enter the name of the point: ";
        std::cin >> pointName;
        checkName(pointName);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the parabola: ";
        std::cin >> parabolaName;
        checkName(parabolaName);
        std::cin.ignore(MAX_SIZE, '\n');
    }

    if (secondChoiceNumber == ELEVENTH_CHOICE)
    {
        std::cout << "Enter the point coordinates: ";
        std::cin >> x >> y;
        std::cout << "Enter the parabola coeficients: ";
        std::cin >> a >> b >> c;
        if (pointLiesOnParabola(x, y, a, b, c) == 1)
        {
            std::cout << "The tangent through point " << pointName << " towards the parabola " << parabolaName << ":";
            findTangentThroughPointOnParabola(x, y, a, b, c);
        }
        else
        {
            std::cout << "The tangent(s) through point " << pointName << " towards the parabola " << parabolaName << ":" << std::endl;
            findTangentThroughPointNotOnParabola(x, y, a, b, c);
        }
    }
}

void actionsWithParabolaAndLine(char firstChoiceNumber, char secondChoiceNumber)
{
    double a1, b1, c1, a2, b2, c2 = 0.0;
    char parabolaName[MAX_SIZE] = "\0";
    char lineName[MAX_SIZE] = "\0";
    if (firstChoiceNumber == SECOND_CHOICE)
    {
        std::cout << "Enter the name of the parabola: ";
        std::cin >> parabolaName;
        checkName(parabolaName);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the line: ";
        std::cin >> lineName;
        checkName(lineName);
        std::cin.ignore(MAX_SIZE, '\n');
    }

    if (secondChoiceNumber == TWELFTH_CHOICE)
    {
        std::cout << "Enter the coeficients of the parabola: ";
        std::cin >> a1 >> b1 >> c1;
        std::cout << "Enter the coeficients of the line: ";
        std::cin >> a2 >> b2 >> c2;
        std::cout << "The common point(s) of the parabola " << parabolaName << " and the line " << lineName << ":";
        findCommonPointsOfLineAndParabola(a1, b1, c1, a2, b2, c2);
    }
}

void actionsWithFourLines(char firstChoiceNumber, char secondChoiceNumber)
{
    double a1, b1, c1, a2, b2, c2 = 0.0;
    double a3, b3, c3, a4, b4, c4 = 0.0;
    char line1Name[MAX_SIZE] = "\0";
    char line2Name[MAX_SIZE] = "\0";
    char line3Name[MAX_SIZE] = "\0";
    char line4Name[MAX_SIZE] = "\0";

    if (firstChoiceNumber == SECOND_CHOICE)
    {
        std::cout << "Enter the name of the first line: ";
        std::cin >> line1Name;
        checkName(line1Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the second line: ";
        std::cin >> line2Name;
        checkName(line2Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the third line: ";
        std::cin >> line3Name;
        checkName(line3Name);
        std::cin.ignore(MAX_SIZE, '\n');
        std::cout << "Enter the name of the fourth line: ";
        std::cin >> line4Name;
        checkName(line4Name);
        std::cin.ignore(MAX_SIZE, '\n');
    }

    if (secondChoiceNumber == THIRTEENTH_CHOICE)
    {
        std::cout << "Enter the coeficients of the first line: " << std::endl;
        std::cin >> a1 >> b1 >> c1;
        std::cout << "Enter the coeficients of the second line: " << std::endl;
        std::cin >> a2 >> b2 >> c2;
        std::cout << "Enter the coeficients of the third line: " << std::endl;
        std::cin >> a3 >> b3 >> c3;
        std::cout << "Enter the coeficients of the fourth line: " << std::endl;
        std::cin >> a4 >> b4 >> c4;

        std::cout << "The type of quadrilateral which is formed from the first line " << line1Name << ", the second line "
            << line2Name << ", the third line " << line3Name << ", the fourth line " << line4Name << " : ";
        checkFig(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);
    }
}

void printOptions()
{
    std::cout << std::endl;
    std::cout << "This program works with lines which have the type: a*x + b*y + c = 0." << std::endl;
    std::cout << "This program works with parabolas which have the type: y = a*x^2 + b*x + c." << std::endl;
    std::cout << "Please, choose one of these options by entering one of the letters a - k." << std::endl;
    std::cout << "a. Check if a point lies on a line." << std::endl;
    std::cout << "b. With a given line q and a point p, output an equation of a line, parallel to q and p lies on it." << std::endl;
    std::cout << "c. With a give line q and a point p, lying on it, output an equation of a line perpendicular to q with a heel in p." << std::endl;
    std::cout << "d. With two given lines, find their common point if it exists." << std::endl;
    std::cout << "e. Triangle(set with three points) find the equations of its heights, medians and bisectors." << std::endl;
    std::cout << "f. Triangle(set with three points) find the equations of its heights." << std::endl;
    std::cout << "g. Triangle(set with three points) find the equations of its medians." << std::endl;
    std::cout << "h. Triangle(set with three points) find the equations of its bisectors." << std::endl;
    std::cout << "i. With a given equation of a parabola and a point, ";
    std::cout << "find the equation of the tangent towards the parabola in the given point.";
    std::cout << std::endl;
    std::cout << "j. With given equations of a parabola and a line, find their common points." << std::endl;
    std::cout << "k. With given equations of four lines, find the type of quadrilateral they form." << std::endl;
}

void printResults(char firstChoiceNumber, char secondChoiceNumber)
{
    switch (secondChoiceNumber)
    {
      case THIRD_CHOICE:
      case FOURTH_CHOICE:
      case FIFTH_CHOICE:
         actionsPointAndLine(firstChoiceNumber, secondChoiceNumber);
         break;
      case SIXTH_CHOICE:
        actionsTwoLines(firstChoiceNumber, secondChoiceNumber);
        break;
      case SEVENTH_CHOICE:
          actionsWithTriangle(firstChoiceNumber, secondChoiceNumber);
          break;
      case EIGHTH_CHOICE:
      case NINTH_CHOICE:
      case TENTH_CHOICE:
          actionsWithTriangle2(firstChoiceNumber, secondChoiceNumber);
          break;
      case ELEVENTH_CHOICE:
          actionsWithParabolaAndPoint(firstChoiceNumber, secondChoiceNumber);
          break;
      case TWELFTH_CHOICE:
          actionsWithParabolaAndLine(firstChoiceNumber, secondChoiceNumber);
          break;
      case THIRTEENTH_CHOICE:
          actionsWithFourLines(firstChoiceNumber, secondChoiceNumber);
          break;
    }
}

void printOutput(char firstChoiceNumber, char secondChoiceNumber, char closure)
{
    while (true)
    {
        printOptions();
        std::cin >> secondChoiceNumber;

        while (secondChoiceNumber < THIRD_CHOICE || secondChoiceNumber > THIRTEENTH_CHOICE)
        {
            std::cout << "Please, enter one of the letters from a to k." << std::endl;
            std::cin.ignore(MAX_SIZE, '\n');
            std::cin >> secondChoiceNumber;
        }
        std::cin.ignore(MAX_SIZE, '\n');
        printResults(firstChoiceNumber, secondChoiceNumber);
        std::cout << std::endl;
        std::cout << "If you want to close the app press 'C'." << std::endl;
        std::cout << "If you want to continue press any other key." << std::endl;
        std::cin >> closure;
        std::cout << std::endl;

        if (closure == 'C' || closure == 'c') {
            break;
        }
        else
        {
            std::cin.ignore(MAX_SIZE, '\n');
            system("cls");
        }
        
    }
}

void checkFirstChoiceNumber(char firstChoiceNumber)
{
    while (firstChoiceNumber != FIRST_CHOICE && firstChoiceNumber != SECOND_CHOICE)
    {
        std::cout << "Please, enter one of the numbers 1 or 2." << std::endl;
        std::cin.ignore(MAX_SIZE, '\n');
        std::cin >> firstChoiceNumber;
    }
    
}

void printFirstChoices()
{
    std::cout << "Please, choose one of these options by entering the number 1 or 2:" << std::endl;
    std::cout << "1. Input lines with their coefficients and points with their coordinates." << std::endl;
    std::cout << "2. Input lines with their coefficients and names, and points with their coordinates and names." << std::endl;
}

int main()
{
    char firstChoiceNumber = ' ';
    printFirstChoices();
    std::cin >> firstChoiceNumber;
    
    checkFirstChoiceNumber(firstChoiceNumber);
    std::cin.ignore(MAX_SIZE, '\n');
    
    char secondChoiceNumber = ' ';
    char closure = '\0';
    
    printOutput(firstChoiceNumber, secondChoiceNumber, closure);
}