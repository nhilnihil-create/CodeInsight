#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for (int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    vector<int> C(M), D(M);
    rep(i, N) cin >> A[i] >> B[i];
    rep(i, M) cin >> C[i] >> D[i];
    vector<int> res(N);
    rep(i, N)
    {
        int target = 0;
        int dist = INF;
        rep(j, M)
        {
            if (dist > abs(A[i] - C[j]) + abs(B[i] - D[j]))
            {
                dist = abs(A[i] - C[j]) + abs(B[i] - D[j]);
                target = j;
            }
        }
        res[i] = target + 1;
    }
    rep(i, N) cout << res[i] << endl;
    return 0;
}