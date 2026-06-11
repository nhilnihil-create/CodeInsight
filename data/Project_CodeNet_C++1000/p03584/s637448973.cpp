#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
#define ll long long
#define MOD 1000000007

vector<bool> bit(int X) {
	vector<bool> V(30);
	for (int i = 29;i >= 0;i--) {
		V[i] = X & 1;
		X >>= 1;
	}
	return V;
}

int main(){
	int N, K;
	cin >> N >> K;
	vector<bool> KB = bit(K);

	vector<pair<ll, vector<bool>>> W;
	vector<bool> X;
	ll A, B;

	for (int i = 0;i < N;i++) {
		cin >> A >> B;
		W.push_back(make_pair(B, bit(A)));
	}
	sort(all(W));reverse(all(W));

	ll ans = 0, a;
	for (int i = 0;i <= 30;i++) {
		if (!KB[i])continue;
		KB[i] = 0;
		a = 0;
		for (int j = 0;j < N;j++) {
			tie(B, X) = W[j];
			for (int k = 0;k <= i;k++) {
				if ((!KB[k]) && X[k]) {
					B = 0;break;
				}
			}
			a += B;
		}
		KB[i] = 1;
		ans = max(ans, a);
	}
	a = 0;
	for (int j = 0;j < N;j++) {
		tie(B, X) = W[j];
		for (int k = 0;k < 30;k++) {
			if ((!KB[k]) && X[k]) {
				B = 0;break;
			}
		}
		a += B;
	}
	ans = max(ans, a);
	cout << ans << endl;
}