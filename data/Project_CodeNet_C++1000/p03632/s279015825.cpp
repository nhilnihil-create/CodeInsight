#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int l = max(a, c);
    int r = min(b, d);
    if(r - l < 0) cout << 0 << endl;
    else cout << r - l << endl;
}

