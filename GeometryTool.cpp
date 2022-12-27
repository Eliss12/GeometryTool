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

void findCommonPoint(double a1, double b1, double c1, double a2, double b2, double c2)
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
        double y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
        double x = (-b1 * y - c1) / a1;
        std::cout << "(" << x << ";" << y << ")";
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
    double x1, x2, x3, y1, y2, y3, newX, newY, a, b, c = 0.0;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    findMiddle(x1, x2, y1, y2, &newX, &newY);
    findLineThroughTwoPoints(newX, x3, newY, y3, &a, &b, &c); //mediana
    printLine(a, b, c);
    /*findLineThroughTwoPoints(x2, x3, y2, y3, &a,&b,&c);  //heigth
    
    printPerpendicularLineToLine(x1, y1, a, b, c);*/
}