#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;
string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef KEK
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

vector <int> L(vector <int> P) {
	int N = P.size();
	vector <int> stk;
	vector <int> left(N);
	for(int i = 0; i < N; i++) {
		while(!stk.empty() && P[stk.back()] > P[i]) {
			stk.pop_back();
		}
		left[i] = i + 1 - (stk.empty() ? 0 : stk.back() + 1);
		stk.push_back(i);
	}
	return left;
}
int main() {fio;
	int n;
	cin >> n;
	vector <int> P(n);
	for(int i = 0; i < n; i++) {
		cin >> P[i];
	}
	vector <int> left = L(P);
	reverse(all(P));
	vector <int> right = L(P);
	reverse(all(right));
	reverse(all(P));
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans += (ll) P[i] * left[i] * right[i];
	}
	debug(left, right);
	cout << ans << endl;
    return 0;
}