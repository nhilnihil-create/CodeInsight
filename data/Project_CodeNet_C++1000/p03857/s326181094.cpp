#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define x first
#define y second

int n, k, l, d1[200005], d2[200005], r1, r2;
map< pair<int, int>, int > M;

int f1(int x) {
	if ( x == d1[x] ) return x;
	return d1[x] = f1(d1[x]);
}

int f2(int x) {
	if ( x == d2[x] ) return x;
	return d2[x] = f2(d2[x]);
}

int main() {
	scanf("%d%d%d", &n, &k, &l);
	for ( int i = 1; i <= n; i++ ) {
		d1[i] = d2[i] = i;
	}
	for ( int i = 1; i <= k; i++ ) {
		scanf("%d%d", &r1, &r2);
		d1[f1(r1)] = f1(r2);
	}
	for ( int i = 1; i <= l; i++ ) {
		scanf("%d%d", &r1, &r2);
		d2[f2(r1)] = f2(r2);
	}	
	for ( int i = 1; i <= n; i++ ) {
		M[mp(d1[f1(i)], d2[f2(i)])]++;
	}
	for ( int i = 1; i <= n; i++ ) {
		printf(i == n?"%d\n":"%d ", M[mp(d1[f1(i)], d2[f2(i)])]);
	}
	return 0;
}