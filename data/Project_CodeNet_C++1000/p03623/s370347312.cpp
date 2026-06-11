#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    a = abs(a - n);
    b = abs(b - n);
    if (a < b) cout << "A";
    else cout << "B";
}