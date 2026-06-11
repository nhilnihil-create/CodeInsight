#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int iinf = 1 << 29;
const long long linf = 1ll << 61;

#define nnm(x, y) (((y) + (x) % (y)) % (y))
template<typename T> inline T gcd(T x, T y) { if(x < y) swap(x, y); T mod = x % y; if(mod == 0) return y; return gcd(y, mod); }
template<typename T> inline T lmc(T x, T y) { return x / gcd(x, y) * y; }

int main(int argc, char* argv[])
{
	ll K;
	scanf("%lld", &K);
	//ll tempK = K;
	ll h1 = 49;
	h1 += (K / 50);
	K %= 50;
	/*
	while (K >= 50) {
		h1++;
		K -= 50;
	}
	*/
	ll h2 = h1;
	h2 += 40 * (K / 11);
	h1 -= 11 * (K / 11);
	K %= 11;
	/*
	while (K >= 11) {
		h2 += 40;
		K -= 11;
		h1 -= 11;
	}
	*/
	ll h3 = h2;
	h3 += 50 * K;
	h1 -= K;
	h2 -= K;
	/*
	while (K >= 1) {
		h3 += 50;
		K--;
		h1--;
		h2--;
	}
	*/
	printf("50\n");
	for (int i = 0; i < 50; i++) {
		if (i < 39)
			printf("%lld ", h1);
		else if (i < 49)
			printf("%lld ", h2);
		else
			printf("%lld\n", h3);
	}

	/*
	ll a[50];
	for (int i = 0; i < 50; i++) {
		if (i < 39) a[i] = h1;
		else if (i < 49) a[i] = h2;
		else a[i] = h3;
	}
	for (int k = 0; k < tempK; k++) {
		int M = -1;
		int index;
		for (int i = 0; i < 50; i++) {
			if (M < a[i]) {
				M = a[i];
				index = i;
			}
		}
		for (int i = 0; i < 50; i++) {
			if (i == index) a[i] -= 50;
			else a[i]++;
		}
		if (k != tempK - 1) continue;
		printf("%d\n", k + 1);
		for (int i = 0; i < 50; i++) {
			printf("%lld ", a[i]);
		}
		printf("\n");
	}
	*/

	return 0;
}
