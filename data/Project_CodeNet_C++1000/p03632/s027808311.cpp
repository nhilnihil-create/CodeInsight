#include <bits/stdc++.h>
typedef long long  ll;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int bottom = max(a, c);
    int up = min(b, d);
    cout << max(0, up - bottom) << endl;
}
