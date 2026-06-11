#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	int ans = 0;
	for(int i = 1; i < s.size(); i++)
		if(s[i] != s[i - 1]) ans++;
	cout << ans << '\n';
}
