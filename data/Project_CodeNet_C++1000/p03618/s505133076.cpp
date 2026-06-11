#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	string s; 
	cin >> s; 
	int n = s.size();
	long long ans = 0;
	long long cnt[33] = {};
	for(long long i=0;i<n;i++){
		ans+=(i-cnt[s[i]-'a']);
		cnt[s[i]-'a']++;
	}
	cout<<ans+1ll<<endl;
	return 0;
}
