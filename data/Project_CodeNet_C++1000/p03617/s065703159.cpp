#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    ll Q, H, L, D, N;
	cin >> Q >> H >> L >> D >> N;
	H = min(H, Q * 2);
	L = min(L, H * 2);
	D = min(D, L * 2);
	cout << N / 2 * D + (N % 2) * L << endl;
}