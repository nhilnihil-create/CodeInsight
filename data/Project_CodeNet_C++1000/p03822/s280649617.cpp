#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;
//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

int n;
int a[100010];
vector<int> G[100010];
bool used[100010];

void input() {
    cin >> n;
    REP(i,n-1) {
        cin >> a[i];
        G[a[i]].pb(i + 2);
    }
}

int f(int k) {
    if (used[k]) return inf;
    used[k] = 1;
    if (sz(G[k]) == 0) return 0;
    vector<int> v;
    for (int i = 0; i < G[k].size(); i++) {
        v.pb(f(G[k][i]));
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > cnt) {
            cnt = v[i] + 1;
        } else {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    cout << f(1) << endl;
}

int main(int argc, char *argv[]){
    input();
    solve();
    return 0;
}
