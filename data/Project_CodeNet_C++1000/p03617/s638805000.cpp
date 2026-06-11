#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long Q, H, S, D, N;
	cin >> Q >> H >> S >> D >> N;
	S = min({ 4 * Q,2 * H,S });
	if (2 * S < D) cout << N * S << endl;
	else cout << D * (N / 2) + S * (N % 2) << endl;
}