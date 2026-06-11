#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	long long n = s.length();
	map<char, long long> cnt;
	long long ans = 0;
	for(int i = n-1; i >= 0; i--){
		ans += n-1-i-cnt[s[i]];
		cnt[s[i]]++;
	}
	cout << ans+1 << endl;
	return 0;
}