#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;


int main() {
	int N, M; cin >> N >> M;
	ll* A = new ll[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i]--;
	}

	ll* C = new ll[M];
	ll* B = new ll[M];
	for (int i = 0; i < M; i++) { B[i]=0, C[i] = 0; }

	int c = -1;
	for (int i = 0; i < N - 1; i++) {
		if (A[i] > A[i + 1]) { c++; }
		B[A[i + 1]] += (A[i + 1] + M - A[i]) % M;
	}
	for (int i = 0; i < M; i++) {
		C[i] = c;
	}
	for (int i = 0; i <= A[N - 1]; i++) {
		C[i]++;
	}
	for (int i = A[0] + 1; i < M; i++) {
		C[i]++;
	}

	ll s = 0;
	for (int i = 0; i < N - 1; i++) {
		s += min((A[i + 1] + M - A[i]) % M, 1 + A[i + 1]);
	}

	ll ans = s;

	//cout << s << endl;
	for (int i = 1; i < M; i++) {
		s -= C[i - 1];
		s += B[i - 1];
		ans = min(ans, s);
		//cout << s << endl;
	}

	cout << ans << endl;
	return 0;
}