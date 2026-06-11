#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int n; cin >> n;
	string sa, sb; cin >> sa >> sb;
	int start; ll ans;
	if( sa[0] == sb[0] ){
		start = 1;
		ans = 3;
	} else {
		start = 2;
		ans = 6;
	}
	for( int i = start; i < n; ++i ){
		if( sa[i] == sb[i] && sa[i-1] == sb[i-1] ){
			ans *= 2;
		} else if( sa[i] == sb[i] && sa[i-1] != sb[i-1] ){
			ans *= 1;
		} else if( sa[i] != sb[i] && sa[i-1] == sb[i-1] ){
			ans *= 2;
			i += 1;
		} else if( sa[i] != sb[i] && sa[i-1] != sb[i-1] ){
			ans *= 3;
			i += 1;
		}
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}