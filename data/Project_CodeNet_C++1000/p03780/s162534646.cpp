#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;

template<class T>bool chmax(T &a, const T &b) { if( a < b ) { a = b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) { if( b < a ) { a = b; return 1; } return 0;}

#ifdef LOCAL
	#define eprintf(...) printf(__VA_ARGS__)
#else 
	#define eprintf(...) 1
#endif

#define ROUNDUP(a, b) 		( ((a) + ((b) - 1) ) / b)
#define SET_ZERO(a)	 		( memset((a), 0, sizeof(a)))
#define SET_NUM_ARRAY(a,b)	( memset((a), b, sizeof(a)))

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int a[5009];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+N, greater<int>() );
	lli sum = 0;
	int ans = N;
	for (int i = 0; i < N; i++) {
		if (a[i] + sum < K) sum += a[i];
		else ans = N - i - 1;
	}

	printf("%d\n", ans);
	return 0;
}

