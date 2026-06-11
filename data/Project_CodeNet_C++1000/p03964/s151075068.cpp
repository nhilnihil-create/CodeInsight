#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(void) {
    int n;
    ull a, b, tmpa, tmpb;

    cin >> n;

    a = 1; b = 1;

    while (n--) {
        cin >> tmpa >> tmpb;
        ull p = max(a / tmpa, b / tmpb);

        while (true) {
            if (p * tmpa >= a && p * tmpb >= b) {
                break;
            }
            p++;
        }

        a = tmpa * p;
        b = tmpb * p;
    }

    cout << a + b << endl;

    return 0;
}
