#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 50;
int n, k, ans;
 
int main() {
	
	cin >> n >> k;
	
	int x;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		if(k - x < x) {
			ans += (k-x)*2;
		}else ans += 2*x;
	}
	cout << ans << endl;
	return 0;
} 
