#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	long long ans = 0;
	bool rest = false;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (rest && A > 0) {
			ans++;
			A--;
		}
		ans += (long long)A / 2;
		rest = A % 2 == 1;
	}
	cout << ans << endl;
}