#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define MOD 1000000007

int main() {
	ll N;
	cin >> N;
	ll d = 1;
	while (1) {
		if (N / (1LL << d) < 1LL) {
			break;
		}
		d++;
	}
	d--;
	N -= (1LL << d);
	ll ad = 99;
	queue<int> Q;
	Q.push(100);
	for (ll i = 0;;i++) {
		if (N & (1LL << i)) {
			Q.push(ad);
			ad--;
		}
		if (i == d)break;
		Q.push(i + 1);
	}
	for (int i = 1;i <= 100;i++) {
		Q.push(i);
	}
	cout << Q.size() << endl;
	while (!Q.empty()) {
		cout << Q.front() << " ";
		Q.pop();
	}
	cout << endl;
}