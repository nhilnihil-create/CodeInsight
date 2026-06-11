#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        mp[a]++;
    }

    int res = 0;
    int num = 0;
    for (auto m : mp) {
        if (m.second % 2 == 1) res++;
        else {
            num++;
        }
    }

    if (num % 2 == 1) --res;

    cout << res + num << endl;

    return 0;
}