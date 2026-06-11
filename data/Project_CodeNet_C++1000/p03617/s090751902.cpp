#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long  Q, H, S, D; // 0.25, 0.5, 1, 2L
	cin >> Q >> H >> S >> D;
	int N;
	cin >> N;
	int divide = N / 2;
	long long ans = 0;
	ans += min({Q * 8, H * 4, S * 2, D}) * divide;
	ans += min({Q * 4, H * 2, S}) * (N % 2);
	cout << ans << endl;
}