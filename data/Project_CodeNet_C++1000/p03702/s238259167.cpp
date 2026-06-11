#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, a, b;
vector <int> h;

bool check(int steps) {
	int c = a - b;
	vector <int> t = h;
	for (int i = 0; i < n; i++) {
		t[i] = max(0LL, t[i] - 1LL * steps * b);
	}
	long long req = 0;
	for (int i = 0; i < n; i++) {
		req += (t[i] + c - 1) / c;
	}
	return req <= steps;
}

int main() {
	cin >> n >> a >> b;
	h.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int l = 0, r = 1e9;
	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r << endl;
	
  	return 0;
}
