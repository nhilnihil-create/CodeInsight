#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9 + 7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e16;
typedef array<int, 3>arr3;
void die(string s) { cout << s << endl; exit(0); }

bool que(ll x) {
	cout << "? " << x << endl;
	char res; cin >> res;
	return (res == 'Y') ? true : false;
}
bool que(string x) {
	cout << "? " << x << endl;
	char res; cin >> res;
	return (res == 'Y') ? true : false;
}
void end(string s) {
	cout << "! " << s << endl;
	exit(0);
}

void solve() {
	int ok = 0, ng = 11;
	//桁数をにぶたん
	//100...0のときやばい
	while (abs(ok - ng) > 1) {
		int mid = (ok + ng) / 2;
		string s = "1";
		REP(i, mid)s += '0';
		bool res = que(s);
		if (res)ok = mid;
		else ng = mid;
	}
	//100...0のとき
	if (ng == 11) {
		ok = 10, ng = 0;
		while (ok - ng > 1) {
			string s = "";
			int mid = (ok + ng) / 2;
			REP(i, mid)s += '9';
			bool res = que(s);
			if (res)ok = mid;
			else ng = mid;
		}
		string ans = "1";
		REP(i, ok - 1)ans += '0';
		end(ans);
	}
	//桁数=ng
	string ans;;
	string tmp = "";
	for (int k = ng; k > 0; k--) {
		string s = tmp;
		ok = 10, ng = 0;
		while (ok - ng > 1) {
			s = tmp;
			int mid = (ok + ng) / 2;
			s += (char)('0' + mid);
			REP(_, k)s += '0';
			bool res = que(s);
			if (res)ok = mid;
			else ng = mid;
		}
		char c = '0';
		//if (ok == 10) {
		//	int n = ans.size();
		//	ans[n - 1]++;
		//	ans += '0';
		//	tmp[n - 1]++;
		//	tmp += '0';
		//	goto END;
		//}
		c = (char)(ok - 1 + '0');
		if (k == 1) {
			if (ok == 10) {
				int n = ans.size();
				ans[n - 1]++;
				c = '0';
			}
			else c = (char)(ok + '0');
		}
		ans += c;
		tmp += c;
	END:;
	}
	end(ans);
}

int to_int(string s) {
	int res = 0;
	REP(i, s.size()) {
		if (s[i] >= '0'&&s[i] <= '9') {
			int num = s[i] - '0';
			res *= 10;
			res += num;
		}
	}
	return res;
}

void test(int x) {
	while (true) {
		string s; cin >> s;
		if (s[0] == '!') {
			int res = to_int(s);
			if (res == x) {
				print("ok"); return;
			}
			else print("no!!!!!!!!!!!"); exit(0);
		}

	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
		solve();
}

