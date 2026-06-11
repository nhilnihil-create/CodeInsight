/**
*    author:  boutarou
*    created: 20.06.2020 00:16:38
**/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define fcout cout << fixed << setprecision(15)
using lint = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const double PI = 3.1415926535897932;

int n;
int a[100005];
int cnt[100005];
int ans[100005];
int out = 0;
vector<int>belong[100005];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, n - 1) {
		cin >> a[i + 1];
		a[i + 1]--;
		cnt[a[i + 1]]++;
	}
	stack<int>st;
	rep(i, n) if (cnt[i] == 0) st.push(i);
	while (!st.empty()) {
		int now = st.top(); st.pop();
		if (belong[now].empty()) ans[now] = 0;
		else {
			int ma = 0;
			sort(belong[now].rbegin(), belong[now].rend());
			rep(i, belong[now].size()) {
				chmax(ma, belong[now][i] + i + 1);
			}
			ans[now] = ma;
		}
		belong[a[now]].emplace_back(ans[now]);
		cnt[a[now]]--;
		if (cnt[a[now]] == 0) st.push(a[now]);
	}
	rep(i, n) {
		chmax(out, ans[i]);
	}
	cout << out << endl;
	
	return 0;
}