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
	int n, k;
	cin >> n >> k;
	vector<int>x(n);
	rep(i, n)cin >> x[i];
	int count = 0;
	rep(i, n) {
		count += 2*min(x[i], k - x[i]);
	}
	cout << count << endl;
	return 0;
}
