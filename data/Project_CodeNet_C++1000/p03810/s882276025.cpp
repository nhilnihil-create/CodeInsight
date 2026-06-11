#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

int a[100100];
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int solve(int n) {
	bool notOne = false;
	int cnt0 = 0;
	int cnt1 = 0;
	FOR(i,0,n) {
		if ((a[i]&1) == 0) {
			cnt0++;
		} else {
			cnt1++;
		}
		if (a[i] > 1) {
			notOne = true;
		}
	}
	if (!notOne) {
		return 0;
	}
	if (cnt0 & 1) {
		return 1;
	}
	if (cnt1 >= 2) {
		return 0;
	}
	FOR(i,0,n) {
		if (a[i] & 1) {
			if (a[i] == 1) {
				return 0;
			}
			a[i]--;
			int g = a[0];
			FOR(j,0,n) {
				g = gcd(g, a[j]);
			}
			FOR(j,0,n) {
				a[j] /= g;
			}
			int val = solve(n);
			return (val ^ 1);
		}
	}
	return -1;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	double beg = clock();
	//freopen("out.txt", "w", stdout);
#endif

	int n;
	scanf("%d",&n);
	LL sum = 0;
	FOR(i,0,n) {
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if (n == 1) {
		if (a[0] > 1) {
			printf("First\n");
		} else {
			printf("Second\n");
		}
		return 0;
	}
	int res = solve(n);
	if (res) {
		printf("First\n");
	} else {
		printf("Second\n");
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
