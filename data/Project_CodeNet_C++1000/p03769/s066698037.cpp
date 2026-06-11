#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL n;
vector<int> L,R;

int main()
{
#ifdef h10
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int i,pos=0;
	scanf("%lld",&n);
	n++;

	for (i=50;i>0;i--)
		if ((n>>i)&1) break;

	for (i--;i>=0;i--)
	{
		R.push_back(++pos);
		if ((n>>i)&1)
			L.push_back(++pos);
	}
	printf("%d\n",pos*2);
	for (i=1;i<=pos;i++)
		printf("%d ",i);
	for (i=(int)L.size()-1;i>=0;i--)
		printf("%d ",L[i]);
	for (i=0;i<(int)R.size();i++)
		printf("%d ",R[i]);
}
