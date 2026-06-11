#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;
ll cnt[26];

void solve()
{
	const int n = s.length();
	ll ans = 1LL*n*(n-1)/2;
	for(int i=0;i<n;++i){
		ans -= cnt[s[i]-'a'];
		cnt[s[i]-'a']++;
	}
	cout << ans+1 << '\n';
}

int main()
{
	cin >> s;
	solve();
	return 0;
}