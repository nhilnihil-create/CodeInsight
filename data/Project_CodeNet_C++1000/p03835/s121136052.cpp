#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int K, S;
	cin >> K >> S;
	int cnt = 0;
	for (int x = 0; x <= K; ++x) {
		for (int y = 0; y <= K; ++y) {
			int z = S - (x + y);
			if (0 <= z && z <= K) ++cnt;
		}
	}
	cout << cnt << endl;
	return 0;
}