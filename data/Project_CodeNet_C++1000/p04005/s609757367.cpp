#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a, b, c, ret;
    cin >>a >>b >>c;
    if (a%2 * b%2 * c%2 == 0) {
        ret = 0;
    }
    else {
        if (max({a,b,c}) == a) {
            ret = b*c;
        } else if (max({a,b,c}) == b) {
            ret = c*a;
        } else {
            ret = a*b;
        }
    }
    cout << ret << endl;
    return 0;
}