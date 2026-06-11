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
    int V[200005];
    rep(i, N) {
        int a;
        cin >> a;
        V[a] = i;
    }
    set<int> S;
    S.insert(-1);
    S.insert(N);
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int now = V[i];
        set<int>::iterator ite = S.upper_bound(now);
        int r = *ite;
        ite--;
        int l = *ite;
        S.insert(now);
        ans += i * (now - l) * (r - now);
    }
    cout << ans << endl;
}
