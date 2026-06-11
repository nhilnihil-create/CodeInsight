#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int x[N],w[N];


int main()
{
	int n,l,t;
	scanf("%d %d %d",&n,&l,&t);
	for(int i=1;i<=n;i++)scanf("%d %d",&x[i],&w[i]);
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(w[i]==1)x[i]+=t;
		else x[i]-=t;
		pos+=x[i]/l;
		if(x[i]%l<0)pos--;
		x[i]=(x[i]%l+l)%l;
	}
	sort(x+1,x+n+1);
	pos=(pos%n+n)%n;
	for(int i=pos+1;i<=n;i++)printf("%d\n",x[i]);
	for(int i=1;i<=pos;i++)printf("%d\n",x[i]);
	return 0;
}