#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c || a + c == b || b + c == a) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
