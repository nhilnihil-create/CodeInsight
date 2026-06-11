#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 200005;
const int mod = 998244353;
vector<int>g[maxn];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<ll,ll>>v;
    f(n) {
        ll x, y;
        cin >> x >> y;
        v.pb({x,y});
    }
    reverse(all(v));
    ll ans = 0;
    for (auto &i : v) {
        ll cur = i.F + ans;
        if (cur != 0)
            cur = ((cur - 1) / i.S + 1) * i.S;
        ans = cur - i.F;
    }
    cout << ans << '\n';
}