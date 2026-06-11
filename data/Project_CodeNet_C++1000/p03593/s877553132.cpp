#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<long long, long long>> vpl;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define inf 999999
#define EPS (1e-7)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define FOR(i, k, n) for (int i = (k); i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.begin(), a.end(), greater<int>()
#define ROT(a) a.begin(), a.begin() + 1, a.end()
#define RROT(a) a.begin(), a.end() - 1, a.end()
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
#define sz(a) a.size()
const ll MOD = 1e9 + 7;
const int MAX = 10000000;
template <typename T1, typename T2>
inline bool chmin(T1& a, T2 b)
{
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T1, typename T2>
inline bool chmax(T1& a, T2 b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//cout << 'H' << endl;
/*--------------------------------------------*/

int main()
{
    //cout << fixed << setprecision(10)
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    int num4 = (H / 2) * (W / 2);
    int num1 = (H % 2) * (W % 2);
    int num2 = (H * W - 4 * num4 - num1) / 2;

    map<char, int> mp;

    rep(i, H * W)
    {
        char c;
        cin >> c;

        mp[c]++;
    }
    //cout << num4 << ' ' << num2 << ' ' << num1 << endl;

    for (auto i : mp) {
        int v = i.second;
        while (v >= 4 && num4 > 0) {
            v -= 4;
            --num4;
        }
        while (v >= 2 && num2 > 0) {
            v -= 2;
            --num2;
        }
        if (v == 1 && num1) {
            --v;
            --num1;
        }
    }

    cout << ((num4 || num2 || num1) ? "No" : "Yes") << endl;
}
