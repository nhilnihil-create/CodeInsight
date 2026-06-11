#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210;

ll n;
int t[maxn],tp;
int q[maxn],head,tail;

int main()
{
	scanf("%lld",&n); ++n;
	while(n) t[++tp]=n&1,n>>=1;
	int k=1; q[head=tail=100]=k;
	for(int i=tp-1;i>=1;i--)
	{
		if(t[i]) q[--head]=++k;
		if(i>1) q[++tail]=++k;
	}
	printf("%d\n",(tail-head+1)*2);
	for(int i=head;i<=tail;i++) printf("%d ",q[i]);
	for(int i=1;i<=k;i++) printf("%d ",i);
	
	return 0;
}
