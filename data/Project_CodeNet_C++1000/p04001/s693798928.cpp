#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
long long dp[100010];
long long h[100010];
const int MOD = 1000000007;

int main()
{
    string s; cin >> s;
    int a[10];
    int len = s.size();
    rep(i, len) a[i] = s[i] - '0';

    ll ans = 0;
    //cout << len << endl;
    rep(i, 1 << len - 1)
    {
        //cout << 1 << endl;
        ll tmp = a[0];
        rep(j, len - 1)
        {
            //tmp = tmp*10 + a[j + 1];
            if (i >> j & 1)
            {
                //cout << i << endl;
                ans += tmp;
                tmp = a[j + 1];
                //cout << ans << endl;
                continue;
            }
            else
            {
                tmp = tmp*10 + a[j + 1];
            }

        }
        ans += tmp;
        // cout << "tmp: " << tmp << endl;
        // cout <<"ans: " << ans << endl;
    }
    cout << ans << endl;
}