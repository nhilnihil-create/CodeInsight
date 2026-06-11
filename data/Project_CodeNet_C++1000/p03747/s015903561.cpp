#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,c,L,T,x[N],w[N],p[N];
int main(){
	scanf("%d%d%d",&n,&L,&T);
	for(int i=0;i<n;i++)
		scanf("%d%d",&x[i],&w[i]);
	for(int i=0;i<n;i++){
		if(w[i]==2)	w[i]=-1;
		int d=x[i]+w[i]*T;
		if(d>0)	c=(c+d/L)%n;
		if(d<0)	c=((c+(d+1)/L-1)%n+n)%n;
		p[i]=(d%L+L)%L;
	}
	sort(p,p+n);
	for(int i=0;i<n;i++)
		printf("%d\n",p[(i+c)%n]);
	return 0;
}
