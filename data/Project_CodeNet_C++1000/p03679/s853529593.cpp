#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, a, b;
    cin >> x >> a >> b;
    b -= a;
    if (b <= 0) cout << "delicious";
    else if (0 < b && b <= x) cout << "safe";
    else cout << "dangerous";
}