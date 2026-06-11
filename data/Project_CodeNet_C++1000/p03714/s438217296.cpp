#include <bits/stdc++.h>
using namespace std;

const int N = (int) 3e5 + 5;
const long long INF = (long long) 1e18;

int n;
int a[N];
long long dpLeft[N], dpRight[N];

void solveLeft() {
	multiset <int> myset;
	multiset <int> :: iterator it;
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		myset.insert(a[i]);
		res += a[i];
	}	
	dpLeft[n] = res;
	for (int i = n + 1; i <= 2 * n; i++) {
		it = myset.begin();
		if (*it >= a[i]) {
			dpLeft[i] = res;
			continue;
		} else {
			res = res - *it + a[i];
			myset.erase(it);
			myset.insert(a[i]);
			dpLeft[i] = res;
		}
	}
}

void solveRight() {
	multiset <int> myset;
	multiset <int> :: iterator it;
	long long res = 0;
	for (int i = 3 * n; i > 2 * n; i--) {
		myset.insert(a[i]);
		res += a[i];
	}	
	dpRight[2 * n + 1] = res;
	for (int i = 2 * n; i > n; i--) {
		it = myset.end();
		it--;
		if (*it <= a[i]) {
			dpRight[i] = res;
			continue;
		} else {
			res = res - *it + a[i];
			myset.erase(it);
			myset.insert(a[i]);
			dpRight[i] = res;
		}
	}
}

int main() {
	//freopen(".inp", "r", stdin); 
	// freopen(".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= 3 * n; i++) {
		scanf("%d", &a[i]);
	}
	solveLeft();
	solveRight();
	long long ans = -INF;
	for (int i = n; i <= 2 * n; i++) {
		ans = max(ans, dpLeft[i] - dpRight[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}