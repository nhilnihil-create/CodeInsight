#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	if(n*2 >= m){
		ans = m/2;
		cout << ans << endl;
	}else{
		ans += n;
		m -= n*2;
		ans += m/4;
		cout << ans << endl;
	}
	return 0;
}