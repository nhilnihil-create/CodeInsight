#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,a[N],num,od,ev,op;
int gcd(int x,int y){ return x ? gcd(y%x,x) : y;}
void GG(int t){ printf(t ? "Second" : "First"); exit(0);} 
int main()
{
	int i,p,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1) GG(1);
	while(1){
		od=ev=0;
		for(i=1;i<=n;i++)
			if(a[i]&1) od++,p=i;
			else ev++;
		if(ev&1) GG(op);
		if(od>=2) GG(op^1);
		if(a[p]==1) GG(op^1);
		a[p]--,k=a[1],op^=1;
		for(i=2;i<=n;i++) k=gcd(k,a[i]);
		for(i=1;i<=n;i++) a[i]/=k;
	  }
	GG(op);
	return 0;
}
