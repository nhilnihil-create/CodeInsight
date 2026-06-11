#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory>
#include <deque>

using namespace std;
#define pf push_front
#define pb push_back
typedef long long LL;
const int maxn = 1005;

deque<int> s,t;LL N;int mx;

int main()
{
	#ifdef Amberframe
		freopen("agc012c.in","r",stdin);
		freopen("agc012c.out","w",stdout);
	#endif
	scanf("%lld",&N);N++;
	for (int i=0;i<50;i++)
		if (N>>i&1) mx=i;
	for (int i=mx-1,o=0;i>=0;i--)
	{
		++o;s.pb(o);t.pb(o);
		if (N>>i&1) ++o,s.pf(o),t.pb(o);
	}
	printf("%d\n",(int)(s.size()+t.size()));
	for (unsigned i=0;i<s.size();i++)
		printf("%d ",s[i]);
	for (unsigned i=0;i<t.size();i++)
		printf("%d ",t[i]);
	return 0;
}