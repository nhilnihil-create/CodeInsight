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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9)+7;
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
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef pair<P, int> PP;
int main(){
	ll a, b, c, d, x;
	cin >> a >> b >> x >> c >> d >> x >> x;
	ll out = a + b + c + d;
	if (a % 2)out--; if (c % 2)out--; if (d % 2)out--;
	if (a > 0 && c > 0 && d > 0) {
		ll sum = (ll)3+b; a--; c--; d--;
		sum += a + c + d;
		if (a % 2)sum--; if (c % 2)sum--; if (d % 2)sum--;
		out = max(out, sum);
	}
	cout << out << endl;
	return 0;
}