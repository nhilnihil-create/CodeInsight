#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    int64_t a, b, x;
    cin >> a >> b >> x;
    cout << b / x - (a % x ? a / x + 1 : a / x) + 1 << endl;
    return 0;
}