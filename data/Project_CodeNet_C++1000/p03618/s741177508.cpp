#include <bits/stdc++.h>

using namespace std;

long long cnt[26];

int main() {
	string a; cin >> a;
	long long n=a.size();
	for(int i=0;i<n;++i)
		++cnt[a[i]-'a'];
	long long ans=n*(n-1)/2+1;
	for(int i=0;i<26;++i)
		ans-=cnt[i]*(cnt[i]-1)/2;
	cout << ans << endl;
	
	return 0;
}
