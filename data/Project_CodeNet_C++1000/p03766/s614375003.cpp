#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

const int maxn = 1E6 + 10;
typedef long long LL;
const LL mo = 1000000007;

int n,sum,f[maxn];

inline int Mul(const LL &x,const LL &y) {return x * y % mo;}
inline int Add(const int &x,const int &y) {return x + y < mo ? x + y : x + y - mo;}

int main()
{
	#ifdef DMC
		freopen("DMC.txt","r",stdin);
	#endif
	
	cin >> n; f[1] = n; f[2] = Mul(n,n);
	for (int i = 3; i <= n; i++)
	{
		f[i] = Add(f[i - 1],sum);
		f[i] = Add(f[i],Mul(n - 1,n - 1));
		f[i] = Add(f[i],n - i + 2);
		sum = Add(sum,f[i - 2]);
	}
	cout << f[n] << endl;
	return 0;
}