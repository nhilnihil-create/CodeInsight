#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

void solve()
{
	const int n = s.length();
	int ans = 0;
	int g = 0, p = 0;
	for(int i=0;i<n;++i){
		if(s[i] == 'g'){
			if(g > p) p++, ans++;
			else g++;
		}else{
			if(g > p) p++;
			else g++,ans--;
		}
	}
	cout << ans << '\n';
}

int main()
{	
	cin >> s;
	solve();
	return 0;
}