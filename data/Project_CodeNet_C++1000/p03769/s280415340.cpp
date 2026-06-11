#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 666;
long long n;
int len;
int c[maxn];
int ans[maxn];
int main()
{
	cin >> n, ++n;
	int len = 0;
	while(n) c[++len] = n & 1, n >>= 1;
	int num = 0, begin = 200, end = 199;
	for(int i = len - 1; i >= 1; --i)
	{
		ans[++end] = ++num;
		if(c[i]) ans[--begin] = ++num;
	}
	cout << ((end - begin + 1) << 1) << endl;
	for(int i = begin; i <= end; ++i) printf("%d ", ans[i]);
	for(int i = begin; i <= end; ++i) printf("%d ", i - begin + 1);
}