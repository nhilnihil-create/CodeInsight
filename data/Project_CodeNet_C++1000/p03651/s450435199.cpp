#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
struct UnionFind {
    vector<int> par, size;
    UnionFind(int x) {
        par.resize(x);
        size.resize(x, 1);
        for(int i = 0; i < x; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int consize(int x) {
        return size[find(x)];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            par[x] = y;
            size[y] += size[x];
        }
         else {
            par[y] = x;
            size[x] += size[y];
        }
    }
};
int mod_pow(int x,int y) {
    int res = 1;
    while(y > 0) {
        if(y%2) {
            res = res*x%mod;
        }
        x = x*x%mod;
        y/=2;
    }
    return res;
}
int fac[2500], finv[2500], inv[2500];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 2500; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
int gcd(int X,int Y) {
    if(X%Y == 0) {
        return Y;
    }
    else {
        return gcd(Y,X%Y);
    }
}
signed main() {
    int N,K;
    cin >> N >> K;
    int mx = 0;
    int GCD = 0;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if(i == 0) {
            GCD = A;
        }
        mx = max(mx,A);
        GCD = gcd(GCD,A);
    }
    cout << ((mx >= K && (mx-K)%GCD == 0)?"POSSIBLE":"IMPOSSIBLE") << endl;
}
