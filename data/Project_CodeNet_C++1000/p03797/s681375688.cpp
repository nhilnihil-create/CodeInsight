#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;

int main() {
	long long N, M;
	cin >> N >> M;
	long long ans=0;
	if (2*N >M) {//Sが余る場合はccを最大限作る
		//cout << "c";
		ans = M / 2;
	}
	else {//Cが余る場合
		ans += N;
		M -= 2 * N;
		ans += M / 4;
	}
	cout << ans;
}