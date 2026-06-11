#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int s = a * b;
    int t = c * d;
    cout << max(s, t) << endl;
    return 0;
}