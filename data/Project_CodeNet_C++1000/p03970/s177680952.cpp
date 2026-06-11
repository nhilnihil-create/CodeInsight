#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int n = s.size();
	string t = "CODEFESTIVAL2016";

	int ans = 0;
	rep(i, n) if(s[i] != t[i]) ans++;
	cout << ans << endl;
}
