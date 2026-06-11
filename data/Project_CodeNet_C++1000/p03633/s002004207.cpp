#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
long long ans , n ;
int main() {
	cin >> n ;
	ans = 1;
	for (int i = 1 ; i <= n ; i ++){
		long long x;
		cin >> x ;
		ans =ans/__gcd(ans,x)*x;
	}
	cout << ans <<endl;
	return 0;
}