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
    int N, x;
    cin >> N >> x;
    int A[N];
    rep(i, N) cin >> A[i];
    int ans = INF;
    vector<int> Min(N, INF);
    for(int i = 0; i < N; i++)  //魔法の回数
    {
        int sum = x * i;
        rep(j, N) {
            Min[j] = min(Min[j], A[(j + i) % N]);
            sum += Min[j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}
