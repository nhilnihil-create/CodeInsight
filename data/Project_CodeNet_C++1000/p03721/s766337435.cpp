#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

const int MAX_N = 110000;

int main()
{
    int N;
    ll K;
    cin >> N >> K;
    vector<pair<ll, ll>> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;

    // sort
    sort(v.begin(), v.end());

    ll res = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i].second;
        if (sum >= K) {
            res = v[i].first;
            break;
        }
    }
    cout << res << endl;
    return 0;
}