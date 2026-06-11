#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

int main(){
	string s;
	cin >> s;
	string ans = "";
	ans+=s[0];
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1])
			ans+=s[i];
	}
	cout << ans.size()-1 << endl;
	return 0;
}
