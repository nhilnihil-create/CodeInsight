#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.size());
	stack<char> c;
	for(int i = 0; i < n; ++i){
		if(s[i] == '0' || s[i] == '1'){
			c.push(s[i]);
		}else{
			if(c.size()) c.pop();
		}
	}
	string ans = "";
	while(c.size()){
		char ac = c.top();
		ans += ac;
		c.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}