#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
//#include <unordered_map>
//#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <db, db> pdd;

int in[105];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) scanf("%d", &in[i]);
	if (M == 1) {
		if (in[1] == 1) {
			printf("1\n1\n1\n");
			return 0;
		}
		printf("%d\n", in[1]);
		printf("2\n");
		printf("%d %d\n", in[1] - 1, 1);
		return 0;
	}

	int c = 0;
	for (i = 1; i <= M; i++) if (in[i] % 2 == 1) c++;

	if (N % 2 == 0 && c > 2) return !printf("Impossible\n");
	if (N % 2 == 1 && c > 1) return !printf("Impossible\n");

	if (N % 2 == 1 && c == 1) {
		int p = 0;
		for (i = 1; i <= M; i++) if (in[i] % 2 == 1) p = i;
		swap(in[1], in[p]);
	}
	if (N % 2 == 0 && c == 2) {
		int p1 = 0, p2 = 0;
		for (i = 1; i <= M; i++) {
			if (in[i] % 2 == 1) {
				if (p1 == 0) p1 = i;
				else p2 = i;
			}
		}
		swap(in[1], in[p1]);
		swap(in[M], in[p2]);
	}
	for (i = 1; i <= M; i++) printf("%d ", in[i]);
	if (in[1] != 1) {
		printf("\n%d\n", M);
		in[1]--, in[M]++;
		for (i = 1; i <= M; i++) printf("%d ", in[i]);
	}
	else {
		printf("\n%d\n", M - 1);
		in[M]++;
		for (i = 2; i <= M; i++) printf("%d ", in[i]);
	}
	return !printf("\n");
}