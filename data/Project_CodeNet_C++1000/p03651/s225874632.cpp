#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int ngcd(vector<int> a) {
	int res;
	res = a[0];
	for (int i = 1; i < a.size() && res != 1; i++) {
		res = gcd(a[i], res);
	}
	return res;
}
#define rep(i,n) for(int i =0;i < n;i++)
int main() {
	int n, k, m = 0;cin >> n >> k;vector<int> a(n);
	
	rep(i, n) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	int G = ngcd(a);
	if (k <= m && k % G == 0) {
		cout << "POSSIBLE" << endl;
	}
	else
		cout << "IMPOSSIBLE" << endl;
}