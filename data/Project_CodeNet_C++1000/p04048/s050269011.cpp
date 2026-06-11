#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

llint n, x;

llint f (llint a, llint b) {
    if (a < b) swap(a, b);
    if (a % b == 0) return (a/b * 2 - 1) * b;
    return a / b * b * 2 + f(a % b, b);
}

int main () {
    cin >> n >> x;
    cout << n + f(n - x, x);
    return 0;
}
