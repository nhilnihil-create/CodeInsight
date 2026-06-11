#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+10;
int n,m,dat[MAXN],o1,o2,st;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&dat[i]);
	for(int i=1;i<=m;i++)
		if(dat[i]&1)
			if(!o1) o1=i;
			else if(!o2) o2=i;
			else return puts("Impossible"),0;
	
	if(o1) swap(dat[1],dat[o1]);
	if(o2) swap(dat[m],dat[o2]);
	for(int i=1;i<=m;i++) printf("%d ",dat[i]);
	
	if(m==1) m++;
	dat[1]--;dat[m]++;st=dat[1]?1:2;
	printf("\n%d\n",m-st+1);
	for(int i=st;i<=m;i++) printf("%d ",dat[i]);
	return 0;
}