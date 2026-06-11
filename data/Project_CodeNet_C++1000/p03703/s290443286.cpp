#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<ll,int>;

struct BIT{
    int N = 0;
    vector<ll> bit;
    void init(int n){
        N = 1;
        while(N<=n) N<<=1;
        bit.resize(N+1);
    }
    void add(int i, ll x){
        while(i<=N){
            bit[i] += x;
            i += i&-i;
        }
    }
    ll sum(int i){
        ll res = 0;
        while(i>0){
            res += bit[i];
            i -= i&-i;
        }
        return res;
    }
};

int main(){
    ll N, K;
    cin >> N >> K;
    vector<P> a(N+1);
    for(int i=0;i<N;i++){
        cin >> a[i+1].first;
        a[i+1].first -= K;
        a[i+1].second = (i+2);
    }
    a[0].second = 1;
    for(int i=0;i<N;i++){
        a[i+1].first += a[i].first;
    }
    sort(a.begin(), a.end());
    BIT bit;
    bit.init(N+1);
    ll ans = 0;
    for(int i=0;i<=N;i++){
        int idx = abs(a[i].second);
        ans += bit.sum(idx);
        bit.add(idx, 1);
    }
    cout << ans << endl;
    return 0;
}
