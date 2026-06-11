#include <bits/stdc++.h>
using namespace std;
//GCD
long long gcd(long long x, long long y){
	if( y == 0 ) return x;
	return gcd(y, x % y);
}
int main() {
	// your code goes here
	long long n,x;
	cin >> n >> x;
	cout << 3*(n-gcd(n,x)) << endl;
	return 0;
}