#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	int n = s.size();
	vector<bool> used(26);
	rep(i, n) used[s[i]-'a'] = true;
	int ans = 1e9;
	rep(i, 26){
		if(!used[i]) continue;
		char p = 'a'+i;
		int j = 0;
		int maxlen = 0;
		while(j < n){
			int len = 0;
			while(j < n && s[j] != p) j++, len++;
			maxlen = max(maxlen, len);
			j++;
		}
		ans = min(ans, maxlen);
	}
	cout << ans << endl;
	return 0;
}
