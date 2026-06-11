#include  <bits/stdc++.h>

using namespace std;

long long n,op[120],tot;
deque <int> L;
int main()
{
	scanf("%lld",&n); n++; while(n>1)
	{
		op[++op[0]]=n&1; n>>=1;
	}tot=1;
//	for(int i=1;i<=op[0];i++) printf("%d ",op[i]); printf("\n");
	for(int i=op[0];i>=1;i--)
		if(op[i]) L.push_back(tot++),L.push_front(tot++);
		else L.push_back(tot++);
	printf("%lld\n",tot+tot-2);
	for(int i=1;i<tot;i++) printf("%lld ",L.front()),L.pop_front();
	for(int i=1;i<tot;i++) printf("%lld ",i);
	printf("\n");
	return 0;
} 