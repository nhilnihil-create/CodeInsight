#include"bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
typedef pair<int, int> P;

lint N, M, A, B;
map<lint, lint> cnt;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> M;
	REP(i, M) {
		cin >> A >> B;
		cnt[A]++;
		cnt[B]++;
	}
	REP(i, N) {
		if (cnt[i + 1] % 2 == 1) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
