#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)


template <typename T>
struct BIT{
    int n;
    vector<T> d;

    BIT(int sz){
        n = sz+10;
        d.resize(n);
    }

    void add(int i, T x){

        while(i<=n){
            d[i] += x;
            i += i&-i;
        }
    }

    T getSum(int i){
        T ret = 0;

        while(i>0){
            ret += d[i];
            i -= i&-i;
        }
        return ret;
    }
};


int main(){
    int N,K; cin >> N >> K;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
        a[i] -= K;
    }

    vector<ll> sum(N+1);
    ll s = 0;
    rep(i,N){
        s += a[i];
        sum[i+1] = s;
    }

    vector<ll> sorted = sum;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    BIT<ll> bit(N);
    ll res = 0;
    rep(i,N+1){
        int idx = lower_bound(sorted.begin(), sorted.end(), sum[i]) - sorted.begin();
        res += bit.getSum(idx+1);
        bit.add(idx+1,1);
    }
    cout << res << endl;
}