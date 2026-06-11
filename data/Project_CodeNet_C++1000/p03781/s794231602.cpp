#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#define rep(i,n) for(int i = 0;i < n;i++)
#define Rep(i,m,M) for(int i = m;i < M;i++)
#define print(var) cout<<#var" = "<<var<<endl;

typedef long long ll;

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;

int main()
{
	ll X;
	cin >> X;
	ll K = (sqrt(8 * X + 1) - 1) / 2.0 - 1;
//	print(K)
	ll t = K;
	for (;; t++)
	{
//		print(t)
		if (t*(t+1) >= 2*X)
		{
			break;
		}
	}
	cout << t;
}
