////////////////////////////////////////////////////////////////////
// This source code is for Visual Studio
////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <stack>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <deque>
#include <math.h>

#define	numberof(a)	(sizeof(a) / sizeof(a[0]))
#define	INF		UINT64_MAX
#define Rep(i,n) for(int i = 0; i < (n); ++i )

using namespace std;

typedef vector< vector<int> > MAT;
typedef pair<int, int> PINT;
typedef long long ll;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef int64_t s64;

int main()
{
	ll N = 0;
	ll max_len = 0;
	ll ret = 0;

	cin >> N;
	vector<ll> p(N);
	Rep(i, N) {
		cin >> p[i];
	}

	Rep(i, N - 1) {
		if (i + 1 == p[i]) {
			p[i + 1] = p[i];
			ret++;
		}
	}
	if (N == p[N - 1]) {
		ret++;
	}

	cout << ret << endl;

	return 0;
}



