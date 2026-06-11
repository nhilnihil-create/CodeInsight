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
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;


int n;
bool m[1 << 18];
ll a[1 << 18];
ll s[1 << 18];
ll sx[1 << 18];
vector<int> v;
int main() {
	cin >> n;
	cin >> a[0];
	rep1(i, n-1) {
		char t; cin >> t >> a[i];
		if (t == '-') {
			m[i] = true;
			v.push_back(i);
		}
	}
	rep(i, n) {
		s[i + 1] = s[i] + a[i];
		if(!m[i])sx[i + 1] = sx[i] + a[i];
		else sx[i + 1] = sx[i] - a[i];
	}
	ll ans = sx[n];
	rep(i, (int)v.size() - 1) {
		int le = v[i], ri = v[i + 1];
		ll z = sx[le] - (s[ri] - s[le]) + s[n] - s[ri];
		ans = max(ans, z);
	}
	cout << ans << endl;
	//stop
	return 0;
}