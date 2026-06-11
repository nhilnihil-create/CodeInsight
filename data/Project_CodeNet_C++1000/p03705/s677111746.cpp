#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	ll N, A, B; cin >> N >> A >> B;

	ll smin = A * (N - 1) + B;
	ll ssum = A + B * (N - 1);
	cout << max((ll)0, ssum - smin + 1) << endl;

	return 0;
}