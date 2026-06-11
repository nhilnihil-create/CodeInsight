#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>
#include<boost/multiprecision/cpp_int.hpp>


using namespace std;
using namespace boost::multiprecision;

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldb = long double;

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", (double)v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A& a, const B& b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A& a, const B& b) { a = max(a, (A)b); };


template<typename T>
class BIT {
public:
	long long N;
	vector<T> seg;
	BIT(long long N) : N(N) {
		seg.resize(N + 1);
		for (int i = 0; i < N + 1; ++i) seg[i] = 0;
	}

	//i番目にxを加算
	void add(int i, T x) {
		++i;
		while (i <= N) {
			seg[i] += x;
			i += i & (-i);
		}
	}

	//[0,i)の和
	T cumulative(int i) {
		T s = 0;
		while (i > 0) {
			s += seg[i];
			i -= i & (-i);
		}
		return s;
	}

	//[a,b)の和
	T sum(int a, int b) {
		return cumulative(b) - cumulative(a);
	}

	//i番目の要素
	T elem(int i) {
		return sum(i, i + 1);
	}

	//i番目に代入
	void assign(int i, T x) {
		add(i, -elem(i));
		add(i, x);
	}
};


int main() {
	ll N, K; cin >> N >> K;
	vector<ll> A(1+N); REP(i, 1, 1+N) cin >> A[i];
	vector<ll> S(1 + N);
	S[0] = 0;
	REP(i, 1, 1 + N) S[i] = S[i - 1] + A[i] - K;
	vector<ll> I(1 + N); REP(i, 0, 1+N) I[i] = i;
	sort(I.begin(), I.end(), [&](ll a, ll b) {
		if (S[a] == S[b]) return a < b;
		else return S[a] < S[b];
		});
	vector<ll> rank(1 + N); REP(i, 0, 1 + N) rank[I[i]] = i;
	BIT<ll> tree{ 1 + N };
	ll ans = 0;
	for (int i = N; i >= 0; --i) {
		int highrank_n = tree.sum(rank[i], N + 1);
		ans += highrank_n;
		tree.add(rank[i], 1);
	}
	PRI(ans);
	return 0;
}