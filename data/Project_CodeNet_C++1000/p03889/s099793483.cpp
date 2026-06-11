#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

signed main(){
	string s;
	cin >> s;
	bool flag = true;
	int n = s.length();
	for(int i = 0;i < (n + 1) / 2;i++){
		if(s[i] > s[n - i - 1]) swap(s[i],s[n - i - 1]);
		if(!((s[i] == 'b' && s[n - i - 1] == 'd') || (s[i] == 'p' && s[n - i - 1] == 'q'))) flag = false;
	}
	if(flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}