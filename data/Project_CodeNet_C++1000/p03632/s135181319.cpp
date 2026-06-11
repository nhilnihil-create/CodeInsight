#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int l = max(a, c), r = min(b, d);
    cout << max(0, r - l) << endl;
}