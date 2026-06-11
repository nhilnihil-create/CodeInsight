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
vector<int> alf[26]; string s; int n;
int le[26];
int cc = 0;
int app(char x) {
	int res = cc;
	int t = x - 'a';
	int ri = lower_bound(alf[t].begin(), alf[t].end(), cc) - alf[t].begin();
	if (ri == le[t])return n;
	res = alf[t][ri];
	return res;
}
void upd(int x) {
	int ri = lower_bound(alf[x].begin(), alf[x].end(), cc) - alf[x].begin();
	if (ri == le[x])cc = n;
	else cc = alf[x][ri] + 1;
}
int main() {
	cin >> s; n = s.length();
	vector<int> v; v.push_back(n);
	rep(i, n) {
		int t = s[i] - 'a';
		alf[t].push_back(i);
	}
	per(i, n) {
		int cnt = 0; int used[26] = {};
		while (i>=0&&cnt < 26) {
			int t = s[i] - 'a';
			if (!used[t]) {
				used[t] = 1; cnt++;
			}
			i--;
		}
		i++;
		if (cnt == 26)v.push_back(i);
	}
	rep(i, 26) {
		le[i] = alf[i].size();
	}
	reverse(v.begin(), v.end());
	int len = v.size();
	string out; int memo = -1;
	int used[26] = {};
	rep(i, v[0]) {
		used[s[i] - 'a'] = 1;
	}
	per(i, 26) {
		if (!used[i])memo = i;
	}
	out.push_back('a' + memo);
	upd(memo);
	Rep(i,1, len) {
		rep(j, 26) {
			char nex = 'a' + j;
			int chk = app(nex);
			if (chk >= v[i]) {
				out.push_back(nex);
				upd(j);
				break;
			}
		}
	}
	cout << out << endl;
	return 0;
}