#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <utility>
using ll = long long int;
using namespace std;
double pi = 3.141592653589793238;

#define FOR(i,N) for(int i=0;i<N;i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

int bitcnt(int numofbitcnt) {
	int karibitcnt = 0;
	for (int i = 0; i < 32; i++) {
		if (numofbitcnt & 1 << i)karibitcnt++;
	}
	return karibitcnt;
}

int main() {
	int N, K;
	cin >> N >> K;

	ll a[15] = { 0 };
	FOR(i, N) {
		cin >> a[i];
	}
	ll maxcnt = 1e17;
	FOR(i, 1 << N) {
		ll b[15] = { 0 };
		if (bitcnt(i) < K)continue;
		b[0] = a[0];
		for (int j = 1; j < N; j++) {
			if (!(i & 1 << j)){b[j] = a[j]; continue; }
			else { b[j] = max((*max_element(b,b+j))+1, a[j]); }

		}
		ll ness = 0;
		FOR(j, N) {
			ness = ness + b[j] - a[j];
		}
		maxcnt = min(maxcnt, ness);
	}

	cout << maxcnt << endl;
	return 0;
}