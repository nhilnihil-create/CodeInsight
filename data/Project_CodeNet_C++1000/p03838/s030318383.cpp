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
	lli x, y; cin >> x >> y;
	lli ans = abs(x) + abs(y) + 10;
	if (x <= y)ans = min(ans, y - x);
	if (-x <= y)ans = min(ans, y + x + 1);
	if(x<=-y)ans = min(ans, abs(y + x) + 1);
	if (-x <= -y)ans = min(ans, 2 - y + x);

	cout << ans << endl;

	return 0;
}
