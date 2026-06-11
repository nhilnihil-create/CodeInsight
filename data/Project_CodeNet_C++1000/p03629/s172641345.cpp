#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const ll mod = 1000000007;
const ll INF = mod * mod;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
typedef vector<string> svec;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 26; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'a'] = i;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    int n = s.size();

    auto next = calcNext(s);

    vector<int> dp(n + 1, 1<<29);
    vector<pair<char, int> > rec(n + 1, {'?', n});
    dp[n] = 1;
    per(i, n) {
        rep(j, 26) {
            //a～zのうち、遷移後の同上の文字列が最短かつs辞書順最小となるものを選ぼう。
            if(next[i][j] == n) {
                if(dp[i] > 1) { //辞書順にするため
                    dp[i] = 1;
                    rec[i] = {'a' + j, n};
                }
            }
            else if(chmin(dp[i], dp[next[i][j] + 1] + 1)) {
                rec[i] = {'a' + j, next[i][j] + 1};
            }
        }
    }

    string res = "";
    int index = 0;
    while(index < n) {
        auto p = rec[index];
        res += p.first;
        index = p.second;
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}