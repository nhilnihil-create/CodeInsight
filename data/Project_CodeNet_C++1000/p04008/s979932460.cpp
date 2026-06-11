#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9+3;
const ll INF = 1e18+3;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX_V = 1e5;
vector<int> es[MAX_V];
int ans = 0;
int N, K;

int dfs(int now, int pre){
    int size = 1;
    for(auto &e: es[now]){
        if(e == pre) continue;
        int s = dfs(e, now);
        if(s > K) ans++;
        elif(s == K && now != 0) ans++;
        else chmax(size, s+1);
    }
    return size;
}

int main(){
    cin >> N >> K;
    int A;
    cin >> A;
    if(A != 1) ans++;
    rep2(i, 1, N-1){
        cin >> A; A--;
        es[i].pb(A), es[A].pb(i);
    }
    dfs(0, -1);
    cout << ans << endl;
}