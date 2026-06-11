#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int a, b;
    char op;
    cin >> a >> op >> b;
    if (op == '+')
        cout << a + b << endl;
    else
        cout << a - b << endl;
    return 0;
}