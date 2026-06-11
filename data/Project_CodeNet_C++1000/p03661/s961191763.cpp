#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;
bool dp[101][10001];//dp[i + 1][j] : i番目まで見たときjが作れるか否か
int main() {
    int N; cin >> N;
    int a[N]; rep(i, N) cin >> a[i];
    ll frontSum[N]; frontSum[0] = a[0];
    rep(i, N - 1)
        frontSum[i + 1] = frontSum[i] + a[i + 1];
    ll backSum[N]; backSum[N - 1] = a[N - 1];
    rep(i, N - 1)
        backSum[N - i - 2] = backSum[N - i - 1] + a[N - i - 2];
    ll minv = LLINF;
    rep(i, N - 1) {
        ll x = frontSum[i], y = backSum[i + 1];
        minv = min(minv, abs(x - y));
    }
    cout << minv << endl;
}
