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


int main(void)
{
	lli Q, H, S, D; cin >> Q >> H >> S >> D;
	lli N; cin >> N;
	Q *= 4; H *= 2;
	lli one = min(min(Q, H), S);
	lli ans = 0;
	if (one * 2 >= D) ans = (N / 2) * D + (N % 2) * one;
	else ans = N * one;
	cout << ans << endl;

	return 0;
}
