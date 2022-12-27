#include <iostream>

const double CHECK_VALUE1 = -0.0000001;
const double CHECK_VALUE2 = 0.0000001;

bool doesPontLieOnLine(double x, double y, double a, double b, double c)
{
    double check = a * x + b * y + c;
    if(check > CHECK_VALUE1 && check < CHECK_VALUE2)
    {
        return true;
    }
    else { return false; }
}
void printLineParallelToLineThroughPoint(double x, double y, double a, double b, double c)
{
    double newC = a * (-x) + b * (-y);
    if(a == -1.0) {
        std::cout << "-x";
    }
    else if (a == 1.0) {
        std::cout << "x";
    }
    else if (a!=0.0) { std::cout << a << "x"; }

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
    
    if (newC > CHECK_VALUE1) {
        std::cout << "+" << newC;
    }
    else { std::cout << newC; }
    std::cout << "=0";
}

void printPerpendicularLineToLine(double x, double y, double a, double b, double c)
{
    
}

void findCommonPoint(double a1, double b1, double c1, double a2, double b2, double c2)
{
    if(a1 * b2 - a2 * b1 == 0)
    {
        std::cout << "The lines are parallel";
    }
    else
    {
        double y = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
        double x = (-b1 * y - c1) / a1;
        std::cout << "(" << x << ";" << y << ")";
    }
}
int main()
{
    double x, y, z, a, b, c = 0.0;
    char name[100];
    std::cin >> name;
    std::cin.ignore( 2, ' ');
    std::cin >> x >> y >> z;
    std::cin.ignore();
    char name2[100];
    std::cin >> name2;
    std::cin.ignore(2, ' ');
    std::cin >> a >> b >> c;
    findCommonPoint(x, y, z, a, b, c);
}