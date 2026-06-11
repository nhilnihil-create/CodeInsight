#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, h, w;

    cin >> H >> W >> h >> w;

    if (!(H % h) && !(W % w))
    {
        cout << "No" << endl;
        return 0;
    }

    int res[510][510];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            res[i][j] = 1;

    ll sum = H * W;

    for (int i = h - 1; i < H; i += h)
        for (int j = w - 1; j < W; j += w)
            res[i][j] = -h * w, sum -= h * w + 1;

    ll a = H * W - (H - H % h) * (W - W % w);

    ll add = max(0LL, (1LL - sum + a - 1) / a);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (res[i][j] > 0)
                res[i][j] += add;
            else
                res[i][j] -= (h * w - 1) * add;

    cout << "Yes" << endl;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cout << res[i][j] << (j == W - 1 ? "\n" : " ");

    return 0;
}