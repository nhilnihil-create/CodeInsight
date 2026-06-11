#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k, x, y, ans = 0;
	
	cin >> n >> k >> x >> y;
	
	if(n > k){
		ans = k*x + (n-k)*y;
		cout << ans;
		
		return 0;
	}
	
	ans = x*n;
	cout << ans;
	
	return 0;
}
