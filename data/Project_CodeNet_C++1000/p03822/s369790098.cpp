#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<int> g[100010];

int dfs(int v){
    int res = 0;
    vector<int> vec;
    for(auto nv : g[v]) vec.push_back(dfs(nv));
    sort(vec.rbegin(), vec.rend());
    rep(i, vec.size()) res = max(res, vec[i] + i);
    return res + 1;
}

int main(){
    int n;
    cin >> n;
    rep(i, n - 1){
        int a;
        cin >> a;
        a--;
        g[a].push_back(i + 1);
    }
    cout << dfs(0) - 1 << endl;
    return 0;
}
