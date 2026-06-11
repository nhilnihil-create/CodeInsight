#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;

template<class T> struct BIT{
    int n;
    vector<T> node;
    
    BIT(int n_){
        n = n_;
        node.resize(n+1, 0);
    }
    
    T sum(int i){
        T s = 0;
        while(i){
            s += node[i];
            i -= i & -i;
        }
        return s;
    }
    
    void add(int i, T x){
        while(i <= n){
            node[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    int n;
    lint k;
    scanf("%d%lld", &n, &k);
    lint a[n], asum[n+1];
    vector<lint> v(n+1);
    asum[0] = v[0] = 0;
    rep(i, n){
        scanf("%lld", &a[i]);
        a[i] -= k;
        asum[i+1] = asum[i] + a[i];
        v[i+1] = asum[i+1];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    lint ans = 0;
    BIT<int> bit(n+1);
    rep(i, n+1){
        int id = lower_bound(v.begin(), v.end(), asum[i]) - v.begin() + 1;
        ans += (lint)bit.sum(id);
        bit.add(id, 1);
    }
    printf("%lld\n", ans);
}