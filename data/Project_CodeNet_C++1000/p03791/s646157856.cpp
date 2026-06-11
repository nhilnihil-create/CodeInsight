#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <cmath>
#include <map>
#include <set>
#include <iostream>

using namespace std;

#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define EPS 1e-9
typedef long long LL;
const LL MOD = 1e9 + 7;

int main(int argc, char** argv) {
#ifdef HOME
	freopen("in.txt", "rb", stdin);
	freopen("out.txt", "wb", stdout);
#endif
	int N;
	scanf("%d", &N);
	vector<int> v(N);
	REP(i,N)
		scanf("%d", &v[i]);
	LL res = 1;
	int ctr = 0;
	REP(i, N)
	{
		++ctr;
		if (v[i] < (2 * ctr - 1))
		{
			res *= ctr;
			res %= MOD;
			--ctr;
		}
	}
	while(ctr>0)
	{
		res *= ctr;
		res %= MOD;
		--ctr;
	}
	printf("%lld\n", res);
	return 0;
}
