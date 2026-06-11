#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 100000;
int a[N];
int gcd(int a, int b) {
	if (!b)return a;
	else return gcd(b, a%b);
}

bool solve(vector<int>& a) {
	int n = a.size();
	bool eq = false;
	ll sum = 0;
	F(i, n) {
		if (a[i] == 1)eq = true;
		sum += a[i];
	}
	if (eq) {
		if (sum % 2 == n % 2) {
			return false;
		}
		else {
			return true;
		}
	}
	int cnt = 0;
	F(i, n) {
		if (a[i] % 2 == 0) cnt++;
	}
	if (cnt & 1) {
		return true;
	}
	if (cnt != n - 1) {
		return false;
	}
	F(i, n)if (a[i] & 1)a[i]--;
	int gg = a[0];
	F(i, n) {
		gg = gcd(gg, a[i]);
	}
	F(i, n)a[i] /= gg;

	return !solve(a);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	vector<int> V;
	int n; ni(n);
	F(i, n) {
		int x; ni(x);
		V.push_back(x);
	}
	if (solve(V))puts("First");
	else puts("Second");

	return 0;
}
