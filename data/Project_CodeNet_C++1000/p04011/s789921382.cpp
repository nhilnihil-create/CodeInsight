#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k, x, y;
	cin >> n >> k >> x >> y;
	int ans = 0;
	if(n < k){
		ans += n*x;
	}else{
		ans += (k*x + (n - k)*y);
	}
	cout << ans << '\n';
	return 0;
}