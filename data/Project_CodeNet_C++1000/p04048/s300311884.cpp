#include <bits/stdc++.h>
     
using namespace std;

long long gcd(long long x,long long y) {
	return y?gcd(y,x%y):x;
}

int main() {
	long long n,x; cin >> n >> x;
    cout << 3*(n-gcd(n,x)) << endl;
	
	return 0;
}
