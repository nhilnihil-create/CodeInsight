#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <string>
#include <cmath>

# define PI 3.14159265358979323846

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    int loops = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
        int na, nb, nc;
        na = b / 2 + c / 2;
        nb = a / 2 + c / 2;
        nc = a / 2 + b / 2;
        if (a == na || b == na || c == nc) {
            loops = -1;
            break;
        }
        a = na;
        b = nb;
        c = nc;
        ++loops;
    }
    cout << loops << endl;
}