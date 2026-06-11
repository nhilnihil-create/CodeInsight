#define _USE_MATH_DEFINES
#include  <iostream>
#include  <algorithm>
#include  <climits>
#include  <vector>
#include  <string>
#include  <cstring>
#include  <stack>
#include  <queue>
#include  <cmath>
#include  <iomanip>
#include  <set>
#include  <map>
#include  <new>
#include <cstdint>
#include <cctype>
using namespace std;
#define rep(i,n)  for(int i = 0; i < n; i++)
#define lrep(i,n,m)  for(int i = n; i < m; i++)

using ll = long long;
using ld = long double;
using Vii = vector<vector<int> >;
using Gjudge = vector<vector<bool>>;
using Vi = vector<int>;
using Vl = vector<ll>;
using Vd = vector<double>;
using Vld = vector<long double>;
using Vll = vector<vector<ll> >;
using Vldd = vector<vector<ld> >;
using Vs = vector<string>;
using Vb = vector<bool>;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Pli = pair<ll, int>;
using Ti = tuple<int, int, int>;
using Tl = tuple<ll, ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int Mod = static_cast<int>(1e9 + 7);
const int INF = INT_MAX;
const ll LINF = LLONG_MAX / 10;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());
	bool f = true;
	for (int i = 0; i < n;) {
		if (i < (n - 4) && s.substr(i, 5) == "maerd") i += 5;
		else if (i < (n - 6) && s.substr(i, 7) == "remaerd") i += 7;
		else if (i < (n - 4) && s.substr(i, 5) == "esare") i += 5;
		else if (i < (n - 5) && s.substr(i, 6) == "resare") i += 6;
		else {
			f = false;
			break;
		}
	}
	if (f) cout << "YES" << endl;
	else  cout << "NO" << endl;
}
