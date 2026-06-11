#include "bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }


lint c_cnt[26];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	lint N = SZ(s);
	REP(i, N) {
		c_cnt[s[i] - 'a']++;
	}
	lint cnt = 0;
	REP(i, 26) {
		cnt += c_cnt[i] * (c_cnt[i] - 1) / 2;
	}
	cout << N * (N - 1) / 2 - cnt + 1 << endl;
}
