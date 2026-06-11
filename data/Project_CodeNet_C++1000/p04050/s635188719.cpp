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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ld INF = (ld)10000000000000;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int n, m;
int a[1 << 17];
vector<int> ans;

vector<int> v;
int main() {
	cin >> n >> m;
	int cnt = 0;
	rep(i, m) {
		cin >> a[i];
		if (a[i]%2) {
			cnt++; v.push_back(a[i]);
		}
	}
	if (cnt > 2) {
		cout << "Impossible" << endl;
	}
	else {
		if (cnt == 0) {
			int x = a[0];
			if (x % 2) {
				rep(i,x / 2)ans.push_back(2);
			}
			else {
				int le = 0, ri = x - 1;
				int id = 0;
				while (ri - le > 1) {
					if (id == 0) {
						le += 2;
					}
					else {
						ri -= 2;
					}
					id ^= 1;
				}
				rep(i, le / 2)ans.push_back(2);
				ans.push_back(1);
				for (int i = le + 1; i < x - 2; i += 2)ans.push_back(2);
			}
			rep1(i, m - 1) {
				ans.push_back(a[i]);
			}
			ans.push_back(1);
			//a
			rep(i, m) {
				if (i > 0)cout << " "; cout << a[i];
			}
			cout << endl;
		}
		else {
			rep(i, v[0] / 2)ans.push_back(2);
			if (cnt == 1) {
				cout << v[0];
				rep(i, m) {
					if (a[i] % 2)continue;
					cout << " " << a[i];
					ans.push_back(a[i]);
				}
				ans.push_back(1);
				cout << endl;
			}
			else {
				cout << v[0];
				rep(i, m) {
					if (a[i] % 2)continue;
					cout << " " << a[i];
					ans.push_back(a[i]);
				}
				ans.push_back(2);
				vector<int> u;
				rep(i, v[1] / 2)u.push_back(2);
				reverse(u.begin(), u.end());
				rep(i, u.size())ans.push_back(u[i]);
				cout << " " << v[1] << endl;
			}
		}
		cout << ans.size() << endl;
		rep(i, ans.size()) {
			if (i > 0)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	//stop
		return 0;
}

