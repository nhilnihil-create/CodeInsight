#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<limits>
#include<list>
#include <stdio.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0;i < (n); ++i)
#pragma GCC optimize("Ofast")



int main() {
	vector<ll>a(10000), b(10000), c(10000);
	
	cin >> a[0] >> b[0] >> c[0];
	int count = 0;
	if (a[0] % 2 == 1 || b[0] % 2 == 1 || c[0] % 2 == 1) {
		cout << count << endl;
		return 0;
	}
	if (a[0] == b[0] && b[0] == c[0]) {
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 1; i < 1000000;i++) {
		a[i] = (b[i - 1] + c[i - 1]) / 2;
		b[i] = (a[i - 1] + c[i - 1]) / 2;
		c[i] = (a[i - 1] + b[i - 1]) / 2;
		count++;
		if (a[i] % 2 == 1 || b[i] % 2 == 1 || c[i] % 2 == 1) {
			cout << count << endl;
			return 0;
		}
	}
	return 0;
}
