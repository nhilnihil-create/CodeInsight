#include <iostream>
#include <sstream>
#include <stdio.h>
#define _USE_MATH_DEFINES
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
	int N; cin >> N;
	vector<int> L(2 * N); rep(i, 0, 2 * N)cin >> L[i];
	sort(L.begin(), L.end());
	int ans = 0;
	for (int k = 0; k < 2 * N; k += 2)ans += L[k];
	cout << ans << endl;

	return 0;
}