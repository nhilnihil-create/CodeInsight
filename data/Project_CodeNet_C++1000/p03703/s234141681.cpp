#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
#define yn {puts("Yes");}else{puts("No");}

const int MAX_N = 200005;
int bit[MAX_N+1];
int nn = MAX_N; //　1-index
const ll INF = 1002003004005006001;

void adds(int a, int w){
    for(int x = a; x <= nn; x += x & -x) bit[x] += w;
}
int sums(int a){ // bit[1,a]の和を返す.
    int ret = 0;
    for(int x = a; x > 0; x -= x & -x) ret += bit[x];  
    return ret;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    ll a[n+1] = {};
    ll sum[n+1] = {};
    srep(i,1,n+1){
        cin >> a[i];
        a[i] -= k;
        sum[i] = sum[i-1] + a[i];
    }

    ll ans = 0;

    vector<P> c;
    c.push_back(P(-INF,0));
    srep(i,1,n+1){
        c.push_back(P(sum[i], i));
    }
    sort(c.begin(), c.end());
    int f[n+1];
    rep(i,n+1){
        f[c[i].second] = i;
    }
    srep(i,1,n+1)adds(i, 1);

    rep(i,n){
        auto ite = lower_bound(c.begin(), c.end(), P(sum[i], 0));
        ans += sums(n) - sums(ite - c.begin() - 1);
        adds(f[i+1], -1);
    }

    cout << ans << endl;
    return 0;
}
 
 
