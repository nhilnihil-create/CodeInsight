#include <iostream>
#include <algorithm>
#include<string>
#include<cmath>
#include<stack>
#include <vector>
#include<queue>
#include <random>
#include <cstdint>
#include <bitset>
#include <iomanip>
#include<utility>
using namespace std;
using ll = long long;

int main() {
	int n, p[100000],ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n-1; i++) {
		if (p[i] ==i+1) {
			ans++;
			swap(p[i], p[i + 1]);
		}
	}
	if (p[n - 1] == n)ans++;
	cout << ans << endl;
	return 0;
}

