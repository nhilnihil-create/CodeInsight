#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;

int main() {
	ll N;
	cin >> N;
	N++;
	vector<int> bit;
	while (N) {
		bit.push_back(N % 2);
		N /= 2;
	}
	reverse(bit.begin(), bit.end());
	deque<int> p;
	p.push_back(1);
	int k = 2;
	for (int i = 1; i < bit.size(); i++) {
		if (i > 1) p.push_back(k++);
		if (bit[i]) p.push_front(k++);
	}
	cout << (k - 1) * 2 << endl;
	for (int i = 1; i < k; i++) cout << i << " ";
	while (!p.empty()) {
		cout << p.front() << " ";
		p.pop_front();
	}
	cout << endl;
}