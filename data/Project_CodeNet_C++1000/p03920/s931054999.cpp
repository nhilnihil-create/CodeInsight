#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long int n;
	cin >> n;
	vector<long long int> a(10000000+1, 0);
	for (long long int i = 1; i <= 10000000; i++) {
		a[i] = a[i-1]+i;
	}
	vector<long long int>::iterator ite = lower_bound(a.begin(), a.end(), n);
	long long int k = ite-a.begin();
	while (k > 0) {
		cout << k << endl;
		n -= k;
		k--;
		k = min(n, k);
	}
	return 0;
}