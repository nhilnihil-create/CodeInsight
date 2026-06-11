#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	string s; cin >> s;
	string ret = s;
	int cnt = 0;
	for (int i=0; i<n; i++) {
		char now = s[i];
		if (now=='(') cnt++;
		else if (cnt==0) ret = '(' + ret;
		else cnt--;
	}
	for (int i=0; i<cnt; i++) {
		ret = ret + ')';
	}
	cout << ret << endl;
	return 0;
}