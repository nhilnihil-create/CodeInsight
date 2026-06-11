#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
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
#include <algorithm>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef complex<ld> compd;
#define rep(i,n)	for(int i=0;i<n;i++)
#define srep(i,a,n)	for(int i=a;i<n;i++)
#define REP(i,n)	for(int i=0;i<=n;i++)
#define SREP(i,a,n)	for(int i=a;i<=n;i++)
#define rrep(i,n)	for(int i=n-1;i>=0;i--)
#define RREP(i,n)	for(int i=n;i>=0;i--)
#define all(a)	(a).begin(),(a).end()
#define mp(a,b)	make_pair(a,b)
#define mt	make_tuple
#define fst	first
#define scn second
#define bicnt(x)	__buildin__popcount(x)
#define debug(x)	cout<<"debug: "<<x<<endl

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;
const ld eps = 1e-18;
const int dx[] = { 0,1,0,-1 };
const int dy[] = { 1,0,-1,0 };

static char server(string s) {
	int n = 100;
	if (s[0] == '?') {
		ll k = stol(s.substr(2));
		if (k <= n&&s.substr(2) <= to_string(n))	return 'Y';
		if (k > n&&s.substr(2) > to_string(n))	return 'Y';
		else	return 'N';
	}
	else {
		ll k = stol(s.substr(2));
		if (k == n) {
			cout << "suceed!!" << endl;
			exit(0);
		}
		else {
			cout << "failed..." << endl;
			exit(0);
		}
	}
}

char query(ll k) {
	cout << "? " << k << endl;
	//char ret = server("? " + to_string(k));
	char ret;	cin >> ret;
	return ret;
}

void answer(ll k) {
	cout << "! " << k << endl;
	//char ret = server("! " + to_string(k));
}

int main() {
	if (query(1000000001) == 'Y') {
		ll ans = 10;
		while (query(ans - 1) == 'N')	ans *= 10;
		answer(ans / 10);
		return 0;
	}
	ll ans = 1LL;
	while (true) {
		char s = query(ans);
		if (s == 'N') {
			ans /= 10;
			break;
		}
		else {
			ans *= 10;
			if (ans > mod) {
				answer(1e9);
				return 0;
			}
		}
	}
	ll left = ans, right = ans * 10;
	while (left + 5 < right) {
		ll mid = (left + right) / 2;
		char s = query(mid * 10);
		if (s == 'Y')	right = mid;
		else	left = mid;
	}
	for (ll i = left; i <= right; i++) {
		char s = query(i * 10);
		if (s == 'Y') {
			answer(i);
			return 0;
		}
	}
	return 0;
}