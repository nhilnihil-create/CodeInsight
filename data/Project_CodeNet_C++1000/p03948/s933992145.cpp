#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
typedef long long ll;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }
    vector<int> rmax(N);
    int ma = 0;
    for(int i = N - 2; i >= 0; i--) {
        ma = max(A[i + 1], ma);
        rmax[i] = ma;
    }
    vector<int> dif(N);
    ma = 0;
    rep(i, N - 1) {
        dif[i] = rmax[i] - A[i];
        ma = max(dif[i], ma);
    }
    int res = 0;
    rep(i, N - 1) {
        // cout << dif[i] << endl;
        if(dif[i] == ma)
            res++;
    }
    cout << res << endl;
    return 0;
}