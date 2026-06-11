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
const int maxn = 2e5 + 5;
const int mod = 998244353;
int b[maxn];
vector<ll>d;
int getID(ll x) {
    return lower_bound(all(d),x)-d.begin() + 1;
}
void update(int x) {
    while(x < maxn) {
        b[x]++;
        x += x & (-x);
    }
}
int sum(int x) {
    int ret = 0;
    while(x) {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll>pre{0};
    f(n) {
        ll x;
        cin >> x;
        pre.pb(pre.back() + x - k);
    }
    d = pre;
    sort(all(d));
    d.erase(unique(all(d)),d.end());
    ll ans = 0;
    update(getID(0));
    for (int i = 1 ; i < pre.size() ; i++) {
        int tar = getID(pre[i]+1) - 1;
        ans += sum(tar);
        update(getID(pre[i])); 
    }
    cout << ans << '\n';
}