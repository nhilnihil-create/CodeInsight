#include <iostream>
using namespace std;
int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    if ((a%2)*(b%2)*(c%2) == 0) {
        cout << 0 << endl;
    } else {
        long long min = 1000000000000000000;
        if (min > a*b) min = a*b;
        if (min > b*c) min = b*c;
        if (min > c*a) min = c*a;
        cout << min << endl;
    }
}