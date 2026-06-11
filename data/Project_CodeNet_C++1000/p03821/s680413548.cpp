#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

int main(void)
{
    ll n, cnt=0;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    reverse(all(a));
    reverse(all(b));
    rep(i,n){
        if(a[i]%b[i]) cnt += b[i] - a[i]%b[i];
        if(i != n-1) a[i+1] += cnt;
    }
    cout << cnt << endl;
    return 0;
}
