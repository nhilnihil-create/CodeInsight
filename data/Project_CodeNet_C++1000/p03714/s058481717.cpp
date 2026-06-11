#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N), B(N), C(N);
	priority_queue<ll, vector<ll>, greater<ll>> qa;
	priority_queue<ll> qc;

	for(auto &a : A) {
		cin >> a;
		qa.push(a);
	}
	for(auto &b : B) cin >> b;
	for(auto &c : C) {
		cin >> c;
		qc.push(c);
	}

	sort(A.begin(), A.end());
	sort(C.begin(), C.end());

	vector<ll> suml(N+1), sumr(N+1);
	suml[0] = accumulate(A.begin(), A.end(), 0LL);
	sumr[0] = accumulate(C.begin(), C.end(), 0LL);

	for(int i=0;i<N;i++) {
		// 和を大きく
		ll amin = qa.top();
		if (amin < B[i]) {
			suml[i+1] = suml[i] - amin + B[i];
			qa.pop();
			qa.push(B[i]);
		} else {
			suml[i+1] = suml[i];
		}
		// 和を小さく
		ll cmax = qc.top();
		if (cmax > B[N-1-i]) {
			sumr[i+1] = sumr[i] - cmax + B[N-1-i];
			qc.pop();
			qc.push(B[N-1-i]);
		} else {
			sumr[i+1] = sumr[i];
		}
	}

  	ll ans = LLONG_MIN;
	for(int i=0;i<=N;i++) {
		ans = max(ans, suml[i] - sumr[N-i]);
	}
	cout << ans << endl;
}