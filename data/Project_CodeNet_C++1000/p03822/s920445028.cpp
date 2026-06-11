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
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

const int MAX_V = 1e5;
vector<int> es[MAX_V];

int dfs(int now){
    if(es[now].empty()) return 0;
    int ret = 0;
    vector<int> nums;
    for(auto &e: es[now]){
        nums.pb(dfs(e));
    }
    sort(all(nums), greater<int>());
    rep(i, sz(nums)) chmax(ret, nums[i]+i+1);
    return ret;
}

int main(){
    int N;
    cin >> N;
    rep2(i, 2, N){
        int A; cin >> A;
        es[A-1].pb(i-1);
    }
    cout << dfs(0) << endl;
}