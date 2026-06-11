#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	int N, K, X, Y;

	cin >> N >> K >> X >> Y;

	int ans = 0;

	for (int i = 1; i <= N; ++i) {
		if (i <= K) ans += X;
		else ans += Y;
	}

	cout << ans << endl;

	
}