#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long double PI = (acos(-1));
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
int main(){
    ll n, x, tmp, ans = 0; sc(n), sc(x);
    vector<ll> a(n);
    rep(i, 0, n) sc(a[i]);
    rep(i, 1, n){
        tmp = a[i]+a[i-1];
        if (tmp > x) a[i] -= tmp-x, ans += tmp-x;
        a[i] = max(a[i], 0ll);
    }
    cout << ans << endl;
    return 0;
}