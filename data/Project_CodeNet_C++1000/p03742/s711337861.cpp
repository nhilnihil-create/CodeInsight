#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    cout << (abs(x-y) < 2 ? "Brown" : "Alice") << endl;
    return 0;
}