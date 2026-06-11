#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <cassert>
#include <queue>
#include <map>
#include <set>
using namespace std;
using Int = int64_t;
using P = pair<Int, Int>;
const Int INF = 1<<30;
const Int MOD = (Int)1e9 + 7;
const Int MAX_N = (Int)1e5 + 5;
#define debug(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << endl;
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>& p) { os << p.first << " " << p.second; return os; }
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) { for(int i = 0; i < (int) v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : ""); return os; }

vector<int> used;
int ans = INF;
void dfs(int idx, const vector<int> &a, int cnt)
{
    if(used[1])
    {
        ans = min(ans, cnt);
        return;
    }
    if(used[idx]) return;
    used[idx] = 1;
    int v = a[idx];
    dfs(v, a, cnt + 1);
}

void solve()
{
    int n; cin >> n;
    used.resize(n, 0);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    dfs(0, a, -1);
    if(ans == INF)
    {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
