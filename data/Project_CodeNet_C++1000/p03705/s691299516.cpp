#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll mn, mx;
    mn = a*(n-1) + b;
    mx = b*(n-1) + a;
    if(n == 1 && a == b) cout << 1 << endl;
    else if(a > b || n == 1) cout << 0 << endl;
    else cout << mx - mn + 1 << endl;
    return 0;
}
