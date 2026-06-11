#include <iostream>
using namespace std;

int main()
{
    int X, t,rest;
    cin >> X >> t;
    rest=X-t;
    if (rest < 0) {
        rest = 0;
    }
    cout << rest;
}