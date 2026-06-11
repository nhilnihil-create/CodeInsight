#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int gcd(int x, int y) {
	if(x < y) return (x == 0) ? y : gcd(y%x, x);
	return (y == 0) ? x : gcd(x%y, y);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	int pl = 0;
	while(true) {
		int odd = 0, even = 0;
		for(int i = 0; i < N; i++)
			if(A[i] % 2) odd++;
			else even++;
		if(even % 2 != 0) break;
		if(odd != 1 && even % 2 == 0) {
			pl = 1-pl;
			break;
		}
		bool fail = false;
		for(int i = 0; i < N; i++) if(A[i] % 2) {
			if(A[i] == 1) {
				fail = true;
				break;
			}
			A[i]--;
			int g = 0;
			for(int j = 0; j < N; j++) g = gcd(g, A[j]);
			for(int j = 0; j < N; j++) A[j] /= g;
			break;
		}
		pl = 1-pl;
		if(fail) break;
	}
	cout << (pl ? "Second\n" : "First\n");
	return 0;
}

// look at my code
// my code is amazing
