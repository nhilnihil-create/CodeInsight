#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,b[N];
long long k,x[N],tmp[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=n;i;i--)	x[i]-=x[i-1];
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=n;i++)	b[i]=i;
	for(int x,i=1;i<=m;i++){
		scanf("%d",&x);
		swap(b[x],b[x+1]);
	}
	while(k){
		if(k&1){
			for(int i=1;i<=n;i++)	tmp[i]=x[i];
			for(int i=1;i<=n;i++)	x[i]=tmp[b[i]];
		}
		k>>=1;
		for(int i=1;i<=n;i++)	tmp[i]=b[i];
		for(int i=1;i<=n;i++)	b[i]=tmp[tmp[i]];
	}
	double sum=0;
	for(int i=1;i<=n;i++)
		sum+=x[i],printf("%.1lf\n",sum);
	return 0;
}
