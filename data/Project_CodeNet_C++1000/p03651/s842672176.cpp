#include <iostream>
#include <sstream>
#include <stdio.h>
//#define _USE_MATH_DEFINES
#include <math.h>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <bitset>
#include <stack>
#include <queue>
#include <ctype.h>

typedef long long int lli;
#define rep(i,s,N) for(int i=s;i<N;i++)
#define MOD 1000000007
#define more(a,b) (((a)>(b))?(a):(b))
#define less(a,b) (((a)<(b))?(a):(b))

using namespace std;
lli GCD(lli a, lli b) {
	lli x = more(a, b);
	lli y = less(a, b);
	lli r = x % y;
	while (r > 0) {
		x = y;
		y = r;
		r = x % y;
	}

	return y;
}

int main(void)
{
	lli N, K; cin >> N >> K;
	vector<lli> A(N); 
	lli max = 0;
	rep(i, 0, N) {
		lli tmp; cin >> tmp;
		max = more(max, tmp);
		A[i] = tmp;
	}
	lli gcd = A[0];
	if (N >= 2)rep(i, 1, N)gcd = GCD(gcd, A[i]);

	if (K <= max && K % gcd == 0)cout << "POSSIBLE" << endl;
	else cout << "IMPOSSIBLE" << endl;


	return 0;
}