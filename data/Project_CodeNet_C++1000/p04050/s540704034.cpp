#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m,a[N],f[N],b[N],cntb;

void Init()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d",&a[i]); 	
}

void Solve()
{
	int cnt=0,t1,t2;
	for (int i=1;i<=m;++i) 
		if (a[i]&1) 
		{
			cnt++;
			if (cnt==1) t1=i;
			else if (cnt==2) t2=i;
			else break;
		}
	if (cnt>2) { printf("Impossible\n"); return ; }
	if (m==1) 
	{
		if (a[m]==1) printf("%d\n%d\n%d\n",1,1,1);
		else 
		{
			printf("%d\n%d\n",a[m],2);
			printf("%d %d\n",1,a[m]-1);
		}
		return ;
	}
	if (cnt>=1) swap(a[t1],a[1]); 
	if (cnt>=2) swap(a[t2],a[m]);
	if (a[m]==1) cntb=m-1;else cntb=m;
	
	
	for (int i=1;i<=m;++i) printf("%d%c",a[i],i==m?'\n':' ');
	printf("%d\n",cntb); a[1]++; a[m]--;
	for (int i=1;i<=cntb;++i) printf("%d%c",a[i],i==cntb?'\n':' ');
}

int main()
{
	Init();
	Solve();
	return 0;
}