#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	ll i, o, t, j, l, s, z;
	cin >> i >> o >> t >> j >> l >> s >> z;
	ll ans = (i-i%2)+(j-j%2)+(l-l%2);
	ll cnt = i%2 + j%2 + l%2;
	bool flag = ( i > 0 && j > 0 && l > 0 );
	if( flag && cnt == 2 ){
		ans += 1;
	} else if( flag && cnt == 3 ){
		ans += 3;
	}
	cout << ans+o << endl;
	return 0;
}