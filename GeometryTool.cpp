#include <iostream>

const double CHECK_VALUE1 = -0.0000001;
const double CHECK_VALUE2 = 0.0000001;

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
    if (a == -1.0) {
        std::cout << "-x";
    }
    else if (a == 1.0) {
        std::cout << "x";
    }
    else if (a != 0.0) { std::cout << a << "x"; }

    if (b == -1.0) {
        std::cout << "-y";
    }
    else if (b == 1.0) {
        std::cout << "+y";
    }
    else if (b > CHECK_VALUE2 && b != 1.0) {
        std::cout << "+" << b << "y";
    }
    else { std::cout << b << "y"; }

    if (c > CHECK_VALUE2) {
        std::cout << "+" << c;
    }
    else if (c < CHECK_VALUE1) { std::cout << c; }
    std::cout << "=0";
}
void printLineParallelToLineThroughPoint(double x, double y, double a, double b, double c)
{
    double newC = a * (-x) + b * (-y);
    printLine(a, b, newC);
}

void printPerpendicularLineToLine(double x, double y, double a, double b, double c)
{
    double newA = -b;
    double newB = a;
    double newC = -a * y + b * x;
    printLine(newA, newB, newC);
}

void findCommonPoint(double a1, double b1, double c1, double a2, double b2, double c2, double* x, double* y)
{
    if(a1 * b2 - a2 * b1 == 0)
    {
        std::cout << "The lines are parallel";
    }
    else if (a1 == a2 && b1 == b2 && c1 == c2)
    {
        std::cout << "The lines match";
    }
    else
    {
        *y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
        *x = (-b1 * *y - c1) / a1;
        /*std::cout << "(" << *x << ";" << *y << ")";*/
    }
}

void findLineThroughTwoPoints(double x1, double x2, double y1, double y2, double* a, double* b, double* c)
{
    *a = y1 - y2;
    *b = x2 - x1;
    *c = (x1 - x2) * y1 + (y2 - y1) * x1;
}

void findMiddle(double x1, double x2, double y1, double y2, double* newX, double* newY)
{
    *newX = x2 - x1;
    *newY = y2 - y1;
}

double pow(double number, int power)
{
    double result = 1;
    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    return result;
}

bool pointLiesOnParabola(double x, double y, double a, double b, double c)
{
    if (a * pow(x, 2) + b * x + c == 0)
    {
        return true;
    }
    else { return false; }
}

void findTangentThroughPointOnParabola(double x, double y, double a, double b, double c)
{
    double newA = 2 * a * x + b;
    double newB = -1;
    double newC = -a * pow(x, 2) + c;
    printLine(newA, newB, newC);
}

void findCommonPointsOfLineAndParabola(double a1, double b1, double c1, double a2, double b2, double c2)
{
    double discriminant = pow(a2 + b1 * b2, 2) - 4 * a1 * b2 * (b2 * c1 + c2);
    if (discriminant < CHECK_VALUE1) { std::cout << "There is no common point"; }
    else if (discriminant > CHECK_VALUE1 && discriminant < CHECK_VALUE2)
    {
        double x = (-a2 - b1 * b2) / 2 * a1 * b2;
        double y = a1 * pow(x, 2) + b1 * x + c1;
        std::cout << "(" << x << ";" << y << ")";
    }
    else
    {
        double x1 = (-a2 - b1 * b2 + sqrt(discriminant)) / 2 * a1 * b2;
        double x2 = (-a2 - b1 * b2 - sqrt(discriminant)) / 2 * a1 * b2;
        double y1 = a1 * pow(x1, 2) + b1 * x1 + c1;
        double y2 = a1 * pow(x2, 2) + b1 * x2 + c1;
        std::cout << "(" << x1 << ";" << y1 << ")" << " " << "(" << x2 << ";" << y2 << ")";
    }

}

bool areTwoLinesParallel(double a1, double b1, double a2, double b2)
{
    double check = a1 * b2 - a2 * b1;
    if (check > CHECK_VALUE1 && check < CHECK_VALUE2)
    {
        return true;
    }
    else { return false; }
}

double findDistanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
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
    findCommonPoint(a3, b3, c3, a4, b4, c4, &x, &y);
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
    else { return false; }
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
    return (distance1 - distance2 < CHECK_VALUE2 && leg == 1) ? true : false;
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

    double distance1 = findDistanceBetweenTwoPoints(x1, x2, y1, y2);
    double distance2 = findDistanceBetweenTwoPoints(x2, x3, y2, y3);

    if (a1 * a3 + b1 * b3 == 0 && distance1 != distance2) { std::cout << "Rectangle"; }
    else if (a1 * a3 + b1 * b3 != 0 && distance1 == distance2) { std::cout << "Rhombus"; }
    else if (a1 * a3 + b1 * b3 == 0 && distance1 == distance2) { std::cout << "Square"; }
    else { std::cout << "Parallelogram"; }
}

void checkFig(double a1, double b1, double c1, double a2, double b2, double c2, double a3, double b3, double c3, double a4, double b4, double c4)
{
    int firstCheck = areTwoLinesParallel(a1, b1, a2, b2);
    int secondCheck = areTwoLinesParallel(a1, b1, a3, b3);
    int thirdCheck = areTwoLinesParallel(a1, b1, a4, b4);
    int fourthCheck = areTwoLinesParallel(a2, b2, a3, b3);
    int fifthCheck = areTwoLinesParallel(a2, b2, a4, b4);
    int sixthCheck = areTwoLinesParallel(a3, b3, a4, b4);
    int sum = firstCheck + secondCheck + thirdCheck + fourthCheck + fifthCheck + sixthCheck;
    
    if (sum >= 3) { std::cout << "Not a quadrilateral"; }
    else if (sum == 0) { std::cout << "Arbitrary quadrilateral"; }
    else
    {
        if (firstCheck == 1)
        {
            if (sixthCheck == 1)
            { checkFig2(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);}
            else { checkTrap(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);}
        }
        else if (secondCheck == 1)
        {
            if (fifthCheck == 1)
            {checkFig2(a1, b1, c1, a3, b3, c3, a2, b2, c2, a4, b4, c4);}
            else {checkTrap(a1, b1, c1, a3, b3, c3, a2, b2, c2, a4, b4, c4);}
        }
        else if (thirdCheck == 1)
        {
            if (fourthCheck == 1)
            {checkFig2(a1, b1, c1, a4, b4, c4, a2, b2, c2, a3, b3, c3);}
            else
            { checkTrap(a1, b1, c1, a4, b4, c4, a2, b2, c2, a3, b3, c3);}
        }
        else if (sixthCheck == 1 && firstCheck == 0)
        { checkTrap(a3, b3, c3, a4, b4, c4, a1, b1, c1, a2, b2, c2); }
        else if (fifthCheck == 1 && secondCheck == 0)
        {checkTrap(a2, b2, c2, a4, b4, c4, a1, b1, c1, a3, b3, c3); }
        else if (fourthCheck == 1 && thirdCheck == 0)
        { checkTrap(a2, b2, c2, a3, b3, c3, a1, b1, c1, a4, b4, c4); }
    }
}
int main()
{
    /*double x, y, z, a, b, c = 0.0;
    char name[100];
    std::cin >> name;
    std::cin.ignore( 2, ' ');
    std::cin >> x >> y >> z;
    std::cin.ignore();
    char name2[100];
    std::cin >> name2;
    std::cin.ignore(2, ' ');
    std::cin >> a >> b >> c;
    findCommonPoint(x, y, z, a, b, c);*/

    /*double x, y, a, b, c = 0.0;
    std::cin >> x >> y >> a >> b >> c;
    std::cout<<doesPointLieOnLine(x, y, a, b, c);*/
    //double x1, x2, x3, y1, y2, y3, newX, newY, a, b, c = 0.0;
    //std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    //findMiddle(x1, x2, y1, y2, &newX, &newY);
    //findLineThroughTwoPoints(newX, x3, newY, y3, &a, &b, &c); //mediana
    //printLine(a, b, c);
    /*findLineThroughTwoPoints(x2, x3, y2, y3, &a,&b,&c);  //heigth
    
    printPerpendicularLineToLine(x1, y1, a, b, c);*/

    /*double x, y, a, b, c = 0.0;
    std::cin >> x >> y >> a >> b >> c;
    findTangentThroughPointOnParabola(x, y, a, b, c);*/

    //double a1, b1, c1, a2, b2, c2 = 0.0;
    //std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    ///*findCommonPointsOfLineAndParabola(a1, b1, c1, a2, b2, c2);*/
    //std::cout<<areTwoLinesParallel(a1, b1, a2, b2);
    double a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4 = 0.0;
    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3 >> a4 >> b4 >> c4;
    checkFig(a1, b1, c1, a2, b2, c2, a3, b3, c3, a4, b4, c4);
}