
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
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<map>
#include<random>
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


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIF(v, n) printf("%."#n"f\n", v)
#define PRIY PRI("Yes")
#define PRIN PRI("No")
template<typename A, typename B>
void mins(A & a, const B & b) { a = min(a, (A)b); };
template<typename A, typename B>
void maxs(A & a, const B & b) { a = max(a, (A)b); };



int main() {
	ll N; cin >> N;
	vector<ll> A(3 * N+1); REP(i, 1, 3 * N+1)cin >> A[i];
	vector<ll> dp1(3 * N+1), dp2(3 * N+1);
	priority_queue<ll, vector<ll>, greater<ll>> qless;
	priority_queue<ll, vector<ll>, less<ll>> qgreater;
	ll sum = 0;
	REP(i, 1, N+1) {
		sum += A[i];
		qless.push(A[i]);
	}
	dp1[N] = sum;
	REP(i, N + 1, 2 * N + 1) {
		sum += A[i];
		qless.push(A[i]);
		sum -= qless.top();
		qless.pop();
		dp1[i] = sum;
	}
	sum = 0;
	for (int i = 3 * N; i >= 2 * N+1; --i) {
		sum += A[i];
		qgreater.push(A[i]);
	}
	dp2[2*N+1] = sum;
	for (int i = 2 * N; i >= N+1; --i) {
		sum += A[i];
		qgreater.push(A[i]);
		sum -= qgreater.top();
		qgreater.pop();
		dp2[i] = sum;
	}
	ll ans = -1e18;
	REP(i, N, 2 * N + 1)maxs(ans, dp1[i] - dp2[i + 1]);
	PRI(ans);
	return 0;
}