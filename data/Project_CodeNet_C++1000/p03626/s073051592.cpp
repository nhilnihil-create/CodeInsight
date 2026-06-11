#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <limits.h>
#include <bitset>
#include <math.h>
#define int long long
using namespace std;
using P = pair<int, int>;
using ll = long long;
using prique = priority_queue<int>;
const int MOD = 1000000007;
const int INF = LLONG_MAX/3;
const int MAX = 510000;

/*-----Library-----*/

struct UnionFind {
    vector<int> par; // 親ノード
    vector<int> rank; // ランク
    vector<int> sizeuf; //要素数
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n); rank.resize(n); sizeuf.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
            sizeuf[i]=1;
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        sizeuf[x]+=sizeuf[y];
        return true;
    }

    int size(int x){
        return sizeuf[root(x)];
    }
};

long long gcd(long long a,long long b){
    if(b==0)return a;
    return gcd(b,a%b);
}

long long lcm(long long i,long long j){
    return i*(j/gcd(i,j));
}

long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/*-----Library-----*/
signed main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=1;
    int cnt=1;
    for(int i=0;i<n;i++){
        if(s[i]==t[i]){
            if(i==0){
                cnt=3;
            }else if(s[i-1]==t[i-1]){
                cnt*=2;
            }else{
                ans*=cnt;
                cnt=1;
            }
        }else{
            if(i==0){
                cnt=6;
            }else if(s[i-1]==t[i-1]){
                ans*=cnt;
                cnt=2;
            }else{
                cnt*=3;
            }
            i++;
            ans%=MOD;
        }
    }
    ans*=cnt;
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}
