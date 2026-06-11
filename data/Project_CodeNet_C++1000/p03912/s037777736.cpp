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
#include<deque>
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
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
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
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cout << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

void solve() {
	int n, m; cin >> n >> m;
    vector<int> x(n);
    map<int, int> mp;
    rep(i, n) {
        cin >> x[i];
        mp[x[i]] ++;
    }
    int cnt0 = 0, ans = 0;
    for(int k = 0; m * k <= 100000; ++k) {
        int y = m * k;
        cnt0 += mp[y];
    }
    ans += cnt0 / 2;
    for(int i = 1; i <= m; ++i) {
        int j = m - i;
        if(i > j) continue;
        else if(i < j) {
            int cnti = 0, cntj = 0;
            for(int k = 0; m * k + i <= 100000; ++k) {
                int y = m * k + i, z = m * k + j;
                cnti += mp[y];
                cntj += mp[z];
            }
            if(cnti <= cntj) {
                ans += cnti;
                int cnt = cntj - cnti; //同じカードのペアとして使えるカードの数
                for(int k = 0; m * k + j <= 100000; ++k) {
                    int z = m * k + j;
                    int c = mp[z];
                    if(cnt == 0) break;
                    if(c >= 2) {
                        int d = c / 2;
                        if(cnt >= 2 * d) {
                            ans += d; cnt -= 2 * d;
                        } else {
                            ans += cnt / 2; cnt = 0;
                        }
                    }
                    if(cnt == 0) break;
                }
            }

            if(cnti > cntj) {
                ans += cntj;
                int cnt = cnti - cntj; //同じカードのペアとして使えるカードの数
                for(int k = 0; m * k + i <= 100000; ++k) {
                    int z = m * k + i;
                    int c = mp[z];
                    if(cnt == 0) break;
                    if(c >= 2) {
                        int d = c / 2;
                        if(cnt >= 2 * d) {
                            ans += d; cnt -= 2 * d;
                        } else {
                            ans += cnt / 2; cnt = 0;
                        }
                    }
                    if(cnt == 0) break;
                }
            }
        } else if(i == j) {
            int cnt = 0;
            for(int k = 0; m * k + i <= 100000; ++k) {
                int y = m * k + i;
                cnt += mp[y];
            }
            ans += cnt / 2;
        }
    }
    cout << ans << endl;
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