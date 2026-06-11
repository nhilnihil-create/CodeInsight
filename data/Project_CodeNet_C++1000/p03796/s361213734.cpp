#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	
	long long c = 1;
	while(n > 0) {
		c = (c * n) % 1000000007;
		n--;
	}
	
	cout << c << endl;
	
}