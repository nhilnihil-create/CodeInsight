#include<iostream>
#include<string>
#include<cstdio>
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
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	/*vector<int> r;
	r.push_back(a[0]);
	rep(i, n) {
		if (i + 1 < n&&a[i] < a[i + 1]) {
			r.push_back(a[i + 1]);
		}
		else {
			r.push_back(a[i] + 1);
		}
	}
	a = r; n++;*/
	//rep(i, n)cout << r[i] << endl;
	string ans = "First";
	rep1(i, n) {
		if (a[n - i] >= i) {
			if (n - i - 1 < 0 || a[n - i - 1] < i) {
				int r = a[n - i] - i;
				if (r % 2 == 0) {
					ans = "Second";
				}
				break;
			}
			else {
				if (a[n - i] > i&&a[n-i-1]==i) {
					ans = "Second";
					int tmp = 0;
					int cur = n - i - 1;
					while (cur >= 0 && a[cur] == i) {
						tmp ^= 1; cur--;
					}
					if (tmp % 2)ans = "First";
					int r = a[n - i] - i;
					if (r % 2)ans = "First";

					break;
				}
			}
		}
		if (a[n - i] == i) {
			int tmp = 1;
			int cur = n - i - 1;
			while (cur >= 0 && a[cur] == i) {
				tmp ^= 1; cur--;
			}
			if (tmp % 2)ans = "Second";
			break;
		}
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();

	//cout << "finish" << endl;
	//stop
	return 0;
}