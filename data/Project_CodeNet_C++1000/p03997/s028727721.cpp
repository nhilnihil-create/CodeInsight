#include <iostream>
using namespace std;

int main (void) {
    int a, b, h;
    int Trapezoid = 0;
    
    cin >> a >> b >> h;

    Trapezoid = (a + b) * h / 2;

    cout << Trapezoid;
    
    return 0;
}
