#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;
    if(a*b<0) {
        cout << "Zero" << endl;
        return 0;
    }
    if(a > 0 || (b - a)%2) {
        cout << "Positive" << endl;
    } else {
        cout << "Negative" << endl;
    }

    return 0;
}