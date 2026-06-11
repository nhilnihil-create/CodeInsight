#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <stack>
#include <deque>
#include <queue>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; string s;
	cin >> n >> s;
	deque<char> Q;
	for (int i = 0; i < n; i++) {
		if (Q.size() && Q.back() == '(' && s[i] == ')') Q.pop_back();
		else Q.push_back(s[i]);
	}
	int countL = 0, countR = 0;
	while (Q.size()) {
		char now = Q.front();
		Q.pop_front();
		if (now == ')') countL++;
		else countR++;
	}
	while (countL--) cout << '(';
	cout << s;
	while (countR--) cout << ')';
}