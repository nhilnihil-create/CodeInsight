#include <iostream>
using namespace std;

string s;
int n;
int cnt[26];

int main() {
	cin >> s;
	for(char c: s) ++cnt[c-'a'];
	n = s.length();
	long long ans = 1LL*n*(n+1)/2LL+1LL;
	for(int i=0; i< 26; ++i) ans -= 1LL*cnt[i]*(cnt[i]+1)/2LL;
	cout << ans;
	return 0;
}