#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(in) in.begin(),in.end()

using ll = long long;
using namespace std;

struct BIT{
    int n;
    vector<ll> bit;

    BIT(int s){
        bit.resize(s+1,0); n = s;
    }
    ll sum(int i){
        ll res = 0;
        for( ; i>0; i -= i & -i) res += bit[i];
        return res;
    } // i番目(1-indexed)までの和
    void add(int i, ll x){
        for( ; i<=n; i += i & -i) bit[i] += x;
    } // i番目(1-indexed)にxを加える
};

int main(){
    int n, k; cin >> n >> k;
    vector<ll> a(n), sum(n+1,0), copy(n+1,0);
    rep(i,n){
        cin >> a[i], a[i] -= k;
        sum[i+1] = copy[i+1] = sum[i] + a[i];
    }

    sort(all(copy));
    copy.erase(unique(all(copy)), copy.end());
    rep(i,n+1) sum[i] = lower_bound(all(copy), sum[i]) - copy.begin(), sum[i]++;
    int s = copy.size(); // index : 1 ~ s

    ll count = 0;
    BIT ans(s);
    rep(i,n+1){
        count += ans.sum(sum[i]);
        ans.add(sum[i],1);
    }
    cout << count << endl;
    return 0;
}