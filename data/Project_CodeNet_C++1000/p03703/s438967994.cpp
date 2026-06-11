#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
int n;
int a[220000];
// Binary Indexed Tree (Fenwick Tree)
// https://youtu.be/lyHk98daDJo?t=7960
template<typename T>
struct BIT {
int n;
vector<T> d;
BIT(int n=0):n(n),d(n+1) {}
void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
    d[i] += x;
    }
}
T sum(int i) { //[0,i]のsum
    T x = 0;
    for (i++; i; i -= i&-i) {
    x += d[i];
    }
    return x;
}
T sum(int l, int r) { // [l,r)のsum
    return sum(r-1) - sum(l-1);
}
};
signed main(){
    int n,k;cin >>n >>k;
    
    rep(i,n)cin >> a[i+1];
    rep(i,n)a[i+1] += a[i];
    vector<P> res;
    rep(i,n+1){
        res.emplace_back(a[i] - i*k,i);
    }
    sort(res.begin(),res.end());
    BIT<int> bit(n+1);
    int ans = 0;
    rep(i,n+1){
        auto hoge = res[i];
        int ind = hoge.second;
        ans += bit.sum(ind);
        bit.add(ind,1);

    }
    cout <<ans << endl;



    return 0;
}