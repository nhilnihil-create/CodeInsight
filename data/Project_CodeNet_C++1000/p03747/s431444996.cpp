#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <complex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <bitset>
#include <limits>
#include <algorithm>
#include <random>
#include <complex>
#include <regex>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define quickIO()	{cin.tie(0);	cout.sync_with_stdio(false);}
#define reach(i,a)	for(auto i:a)
#define rep(i,n)	for(int i=0;i<(int)n;i++)
#define REP(i,n)	for(int i=0;i<=(int)n;i++)
#define srep(i,a,n)	for(int i=a;i<(int)n;i++)
#define SREP(i,a,n)	for(int i=a;i<=(int)n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define pb	push_back
#define fst	first
#define scn second
int bitcnt(ll x) {
	x = ((x & 0xAAAAAAAAAAAAAAAA) >> 1) + (x & 0x5555555555555555);
	x = ((x & 0xCCCCCCCCCCCCCCCC) >> 2) + (x & 0x3333333333333333);
	x = ((x & 0xF0F0F0F0F0F0F0F0) >> 4) + (x & 0x0F0F0F0F0F0F0F0F);
	x = ((x & 0xFF00FF00FF00FF00) >> 8) + (x & 0x00FF00FF00FF00FF);
	x = ((x & 0xFFFF0000FFFF0000) >> 16) + (x & 0x0000FFFF0000FFFF);
	x = ((x & 0xFFFFFFFF00000000) >> 32) + (x & 0x00000000FFFFFFFF);
	return x;
}
int bitcnt(int x) {
	x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
	x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
	x = ((x & 0xF0F0F0F0) >> 4) + (x & 0x0F0F0F0F);
	x = ((x & 0xFF00FF00) >> 8) + (x & 0x00FF00FF);
	x = ((x & 0xFFFF0000) >> 16) + (x & 0x0000FFFF);
	return x;
}
ll gcd(ll a, ll b) {
	return a%b == 0 ? b : gcd(b, a%b);
}
#define debug(x)	cout<<"case #" << x << ": " << endl
#define DEBUG 0
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ld eps = 1e-15;
const int dx[] = { 1,0,-1,0,0 };
const int dy[] = { 0,1,0,-1,0 };

int main() {
	int n; ll l, t;	cin >> n >> l >> t;
	l <<= 1;	t <<= 1;
	vector<ll> ccw, cw;
	vector<pair<ll, int>> dat(n);
	rep(i, n) {
		ll x, w;	cin >> x >> w;	x <<= 1;
		if (w == 1)	cw.push_back(x);
		else	ccw.push_back(x);
		dat[i] = mp(x, w);
	}
	int num = 0;
	if (dat[0].second == 1) {
		rep(i, ccw.size()) {
			// t >= (dist+collision*l)/2
			// collision-1 < (2*t - dist)/l <= collision
			int dist = ccw[i] - dat[0].first;
			int collision = (2 * t - dist + l) / l;
			num = (num + collision) % n;
		}
	}
	else {
		rep(i, cw.size()) {
			int dist = l - (cw[i] - dat[0].first);
			int collision = (2 * t - dist + l) / l;
			num = (((num - collision) % n) + n) % n;
		}
	}
	vector<ll> after(n);
	rep(i, n)	after[i] = (((dat[i].first + (dat[i].second == 1 ? 1 : -1)*t) % l) + l) % l;
	ll afterpos = after[0];
	sort(all(after));
	int pos = 0;
	if (dat[0].second == 1) {
		rrep(i, n) {
			if (after[i] == afterpos) {
				pos = i;
				break;
			}
		}
	}
	else {
		rep(i, n) {
			if (after[i] == afterpos) {
				pos = i;
				break;
			}
		}
	}
	vector<ll> ret(n);
	rep(i, n) {
		ret[num] = after[pos];
		num = (num + 1) % n;
		pos = (pos + 1) % n;
	}
	rep(i, n)	cout << (ret[i] >> 1) << endl;
	return 0;
}