#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

typedef long long llint;

llint a, b, c, d, e, f, g;

llint ff (llint x, llint y, llint z) {
    return x/2*2 + y/2*2 + z/2*2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f >> g;
    cout << max(ff(a, d, e), (a > 0 && d > 0 && e > 0 ? ff(a-1, d-1, e-1) + 3 : 0LL)) + b;
    return 0;
}
