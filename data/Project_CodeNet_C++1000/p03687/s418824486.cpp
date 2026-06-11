#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

void solve()
{
	const int n = s.length();
	int ans = n-1;
	set<char> ch(s.begin(), s.end());
	for(char c : ch){
		int p=-1;
		int cur = 0;
		for(int i=0;i<n;++i)if(s[i]==c){
			cur=max(cur, i-p-1);
			p = i;
		}
		cur=max(cur, n-p-1);
		ans=min(ans, cur);
	}
	cout<<ans<<'\n';
}

int main()
{
	cin >> s;
	solve();
	return 0;
}