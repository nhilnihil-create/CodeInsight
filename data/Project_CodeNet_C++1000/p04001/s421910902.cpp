
// C - たくさんの数式

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

string S;
ll ans = 0;

vector<string> split(string s, string c)
{
	vector<string> ret;
	for(int i = 0, n; i <= s.length(); i = n + 1){

		n = s.find_first_of(c, i);
		if(n == string::npos) n = s.length();
		string tmp = s.substr(i, n - i);
		ret.push_back(tmp);
	}
	return ret;
}

ll calc(string s) {
	//cout << s << endl; // **** debug ****
	ll res = 0;
	vector<string> vals = split(s, "+");
	for (string v : vals) {
		res += stoll(v);
	}
	return res;
}

void dfs(string& s, int i) {
	if (i == S.size()) {
		ans += calc(s);
		return;
	}

	s.push_back(S[i]);
	dfs(s, i+1);
	s.pop_back();

	s.push_back('+');
	s.push_back(S[i]);
	dfs(s, i+1);
	s.pop_back();
	s.pop_back();
}

int main() {
	cin >> S;

	string s;
	s.push_back(S[0]);

	dfs(s, 1);

	cout << ans << endl;

	return 0;
}