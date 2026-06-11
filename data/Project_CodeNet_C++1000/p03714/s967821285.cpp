#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<int, lli> il;
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
	int N;
	scanf("%d", &N);
	int a[300100];
	for (int i = 0; i < 3*N; i++) {
		scanf("%d", &a[i]);
	}

	priority_queue<int, vector<int>, greater<int> > queA;
	priority_queue<int> queB;
	lli sum = 0;
	lli suma[100100];
	SET_ZERO(suma);
	for (int i = 0; i < N; i++) {
		queA.push(a[i]);
		sum += a[i];
	}
	suma[0] = sum;

	for (int i = N; i < 2 * N; i++) {
		queA.push(a[i]);
		sum += a[i];
		sum -= queA.top();
		queA.pop();
		suma[i-N+1] = sum;
	}

	sum = 0;
	for (int i = 2 * N; i < 3 * N; i++) {
		queB.push(a[i]);
		sum += a[i];
	}
	suma[N] -= sum;

	for (int i = 2 * N - 1; i >= N; i--) {
		queB.push(a[i]);
		sum += a[i];
		sum -= queB.top();
		queB.pop();
		suma[i-N] -= sum;
	}

	lli ans = -1001001001001001;
	for (int i = 0; i <= N; i++) {
		chmax<lli>(ans, suma[i]);
	}
	printf("%lld\n", ans);
	return 0;
}																
