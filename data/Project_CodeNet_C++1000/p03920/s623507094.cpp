#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <random>

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x,T a,T b){return a<=x&&x<=b;}
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9+10)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;

#if 1

int main()
{
	ll N;
	cin >> N;

	for(ll hi=1;;hi++)
	{
		vector <ll> ans;
		ll sum = hi*(hi + 1) / 2;
		if (sum >= N)
		{
			for (ll dec = hi; dec >= 0; dec--)
			{
				if(N==0) break;

				if (N - dec >= 0)
				{
					ans.push_back(dec);
					N -= dec;
				}

			}

			reverse(ans.begin(),ans.end());
			for (ll a : ans)
			{
				cout << a << endl;
			}
			return 0;
		}
	}

	return 0;
}



#else

int main()
{
	int H,W;
	cin >> H >> W;

	for (int y = 0; y < H; ++y)
	{
		for (int x = 0; x < W; ++x)
		{
			string s;
			cin >> s;
			if (s == "snuke")
			{
				char a = 'A'+x;
				char b = 1+y;
				printf("%c%d\n",a,b);
				break;

			}

		}
	}



	return 0;
}

#endif