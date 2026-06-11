#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < n; ++i)
using namespace std;
const int INF = 2147483647;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    ll a=0;
    ll ans;
    if(x %11>0 && x%11<=6)  a=1;
    if(x % 11 == 0)
        ans = (x/11)*2-a;
    else
        ans = (x/11)*2+2-a;

    cout << ans << endl;
}

