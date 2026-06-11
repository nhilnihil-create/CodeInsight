#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
typedef vector<lint> poly;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}

const lint mod = 1e9+7;
const lint INF = mod*mod;
const int MAX =100010;

int n, a[MAX];
vector<int> G[MAX];

int dfs(int v){
    vector<int> d;
    for(int nv: G[v]) d.push_back(dfs(nv));
    sort(d.begin(), d.end(), greater<>());
    int ret=0;
    rep(i, G[v].size()) chmax(ret, d[i]+i+1);
    return ret;
}

int main(){
    scanf("%d", &n);
    For(i, 1, n){
        scanf("%d", &a[i]);
        --a[i];
        G[a[i]].push_back(i);
    }
    printf("%d\n", dfs(0));
}