#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

long long n;
string s[2];

long long solve();

int main() {
	cin >> n >> s[0] >> s[1];
	cout << solve() << endl;
	return 0;
}

long long solve() {
	long long ans = 3;
	for(long long i = 0; i < n; i++){
		if(i == 0 && s[0][0] != s[1][0]) {
			ans = 6;//横のセットのとき
			++i;
			continue;
		}
		if(i == 0) continue; // 縦のときは3のまま
		if(s[0][i] == s[1][i]){
			if(s[0][i-1] == s[1][i-1]) ans *= 2;
		} else {
			if(s[0][i-1] == s[1][i-1]) ans *= 2;
			else ans *= 3;
			i++;
		}
		ans %= N;
	}
	return ans;
}
