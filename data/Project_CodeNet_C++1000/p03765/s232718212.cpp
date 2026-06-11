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


int main() {
	string s, t; cin >> s >> t;
	vector<int> s_a(1+s.size());
	vector<int> s_b(1+s.size());
	vector<int> t_a(1+t.size());
	vector<int> t_b(1+t.size());
	s_a[0] = 0;
	s_b[0] = 0;
	t_a[0] = 0;
	t_b[0] = 0;
	REP(i, 1, 1+s.size()) {
		s_a[i] = s_a[i - 1] + (s[i - 1] == 'A' ? 1 : 0);
		s_b[i] = s_b[i - 1] + (s[i - 1] == 'B' ? 1 : 0);
	}
	REP(i, 1, 1+t.size()) {
		t_a[i] = t_a[i - 1] + (t[i - 1] == 'A' ? 1 : 0);
		t_b[i] = t_b[i - 1] + (t[i - 1] == 'B' ? 1 : 0);
	}
	ll q; cin >> q;
	REP(i, 0, q) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll sa = s_a[b] - s_a[a - 1];
		ll sb = s_b[b] - s_b[a - 1];
		ll ta = t_a[d] - t_a[c - 1];
		ll tb = t_b[d] - t_b[c - 1];
		ll smod = ((sa - sb) % 3 + 3) % 3;
		ll tmod = ((ta - tb) % 3 + 3) % 3;
		if (smod == tmod) PRI("YES");
		else PRI("NO");
	}
	return 0;
}