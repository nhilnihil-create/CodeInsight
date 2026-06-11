#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
using LP = pair<ll,ll>;
using P = pair<ll,int>;

int main()
{
    ll a, b, x;
    cin >> a >> b>> x;
    auto div = [&](ll y){
        ll ret = y/x+1;
        if (y < 0) ret = 0;
        return ret;
    };
    ll ans = div(b)-div(a-1);
    cout << ans << endl;
}