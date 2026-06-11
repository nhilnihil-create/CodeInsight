#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int n=s.length();
	vector<int> cnt[26];
	for(int i=0; i<n; i++) cnt[s[i]-'a'].push_back(i);

	ll ans=1;
	for(int i=0; i<n; i++){
		for(int j=0; j<26; j++){
			if(s[i]-'a'==j) continue;
			ans+=cnt[j].end()-lower_bound(cnt[j].begin(), cnt[j].end(), i);
		}
	}
	cout << ans << endl;
	return 0;
}