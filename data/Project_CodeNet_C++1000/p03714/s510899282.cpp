#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int N;
	cin >> N;
	vector<ll> H(3 * N);
	for (int i = 0;i < 3 * N;i++)
		cin >> H[i];

	multiset<ll> l;
	ll ls = 0;
	for (int i = 0;i < N;i++) {
		l.insert(H[i]);
		ls += H[i];
	}
	vector<ll> La(N + 1);
	La[0] = ls;
	auto it = l.begin();
	for (int i = 0;i < N;i++) {
		if (*it < H[N + i]){
			ls -= *it;
			ls += H[N + i];
			l.erase(it);
			l.insert(H[N + i]);
			it = l.begin();
			La[i + 1] = ls;
		}
		else
			La[i + 1] = ls;
	}

	priority_queue<ll> r;
	ll rs = 0;
	for (int i = 3 * N - 1;i >= 2 * N;i--) {
		r.push(H[i]);
		rs += H[i];
	}
	vector<ll> Ra(N + 1);
	Ra[N] = rs;
	ll it2 = r.top();
	for (int i = N - 1;i >= 0;i--) {
		if (it2 > H[N + i]) {
			rs -= it2;
			rs += H[N + i];
			r.pop();
			r.push(H[N + i]);
			it2 = r.top();
			Ra[i] = rs;
		}
		else
			Ra[i] = rs;
	}

	ll ans = La[N] - Ra[N];
	for (int i = 0;i < N;i++) {
		//cout << La[i] << " " << Ra[i] << endl;
		ans = max(La[i] - Ra[i], ans);
	}
	//cout << La[N] << " " << Ra[N] << endl;
	cout << ans << endl;
}