//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    cin >> a;
    vector <array <long long, 2>> dp(n + 1, {-INF, -INF});
    dp[0][0] = 0;
    forn (i, 0, n) {
        if (a[i] > 0) {
            if (a[i] % 2) {
                chkmax(dp[i + 1][0], dp[i][0] + a[i] / 2);
                chkmax(dp[i + 1][0], dp[i][1] + a[i] / 2 + 1);
                chkmax(dp[i + 1][1], dp[i][0] + a[i] / 2);
                chkmax(dp[i + 1][1], dp[i][1] + a[i] / 2);
            } else {
                chkmax(dp[i + 1][0], dp[i][0] + a[i] / 2);
                chkmax(dp[i + 1][0], dp[i][1] + (a[i] - 1) / 2 + 1);
                chkmax(dp[i + 1][1], dp[i][0] + (a[i] - 1) / 2);
                chkmax(dp[i + 1][1], dp[i][1] + (a[i] - 1) / 2 + 1);

            }
        } else {
            dp[i + 1][0] = max(dp[i][0], dp[i][1]);
        }
    }
    cout << *max_element(all(dp[n]));
    return 0;
}