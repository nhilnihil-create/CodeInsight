#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	string s,ans="";
	stack<char>st;
	cin >> s;
	for (auto c : s) {
		if (c != 'B')st.push(c);
		else {
			if (!st.empty())st.pop();
		}
	}
	while (!st.empty()) { ans +=  st.top(); st.pop(); }
	reverse(all(ans));
	cout << ans <<endl;
	return 0;
}

