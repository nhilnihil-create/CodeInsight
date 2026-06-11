#include <iostream>
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


int main() {
	int N; cin >> N;
	int* a = new int[N+1];
	a[0] = 0;

	long ans = 0;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		a[n] = i + 1;
	}

	set<int> st;

	st.insert(0);
	st.insert(N + 1);

	for (int i = 1; i <= N; i++) {
		int k = a[i];
		auto itr1 = st.lower_bound(k);
		auto itr2 = itr1; itr2--;

		long x = k - *itr2;
		long y = *itr1 - k;

		ans += x * y * (long)i;
		st.insert(k);
	}

	cout << ans << endl;
	
	return 0;
}