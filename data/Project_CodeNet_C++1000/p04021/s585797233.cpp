#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define P pair<int, int>
#define F first
#define S second
#define mod 1000000007
#define MOD 998244353
#define INF 40000000000000000
int dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};
signed main(void) {
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i, N) cin >> V[i];
    vector<int> V0 = V;
    sort(all(V0));
    int ans = 0;
    rep(i, N) {
        int a = V[i];
        int j = lower_bound(all(V0), a) - V0.begin();
        if((j - i) % 2 != 0) ans++;
    }
    cout << ans / 2 << endl;
}
