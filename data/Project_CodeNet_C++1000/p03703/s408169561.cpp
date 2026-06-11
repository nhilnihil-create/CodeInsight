#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

struct BIT{
    int N;
    vector<ll> bit;
    void init(int n){
        N = n;
        bit.resize(n+1);
    }
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, ll x){
        while(i <= N){
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    ll n, k, ans = 0;
    cin >> n >> k;
    vector<ll> a(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i+1];
        a[i+1] -= k;
        a[i+1] += a[i];
    }
    vector<P> pos(n+1);
    for(int i=0;i<=n;i++){
        pos[i] = P(a[i],i);
    }
    sort(pos.begin(), pos.end());
    BIT bit;
    bit.init(n+1);
    for(int i=0;i<=n;i++){
        int idx = pos[i].second+1;
        ans += bit.sum(idx);
        bit.add(idx,1);
    }
    cout << ans << endl;
    return 0;
}