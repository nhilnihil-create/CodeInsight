#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;
ll NumberSize(ll N) {
	int cnt = 0;
	while (N > 0) {
		N /= 10;
		cnt++;
	}
	return cnt;
}
int main() {
	ll N;
	cin >> N;
	int ans = NumberSize(N);
	for (ll i = 1; i * i <= N; i++) {
		if (N % i != 0) continue;
		ll B = N / i;
		int size = max(NumberSize(i), NumberSize(B));
		if (ans > size) ans = size;
	}
	cout << ans << endl;
}
