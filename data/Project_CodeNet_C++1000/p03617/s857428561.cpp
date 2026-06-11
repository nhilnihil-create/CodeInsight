#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll q,h,s,d,n; cin>>q>>h>>s>>d>>n;
    ll ans = n/2 * min({8*q,4*h,2*s,d});
    ans += n%2 * min({4*q,2*h,s});
    cout << ans << endl;
    return 0;
}