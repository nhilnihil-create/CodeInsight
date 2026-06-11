#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll c[25];int v[25];
int main(){
	ll n;
	scanf("%lld",&n);
	ll k=1;int m=1;
	while((k<<1)-1<=n){
		k<<=1;
		m++;
	}
	n-=(k-1);
//	printf("%lld\n",n);
	int l=m/2;
	c[0]=1;
	for(int i=1;i<=l;i++)c[i]=c[i-1]*(m-i+1)/i;
	int num=0;
	while(n){
		while(n>=c[l])v[l]++,n-=c[l],num++;
		l--;
	}
	printf("%d\n",m+2*num);
	int id=1;
	for(int i=0;i<m;i++){
		if(i<=m/2)for(int j=0;j<v[i];j++)printf("%d ",++id);
		printf("1 ");
	}
	while(id>1)printf("%d ",id--);
	puts("");
	return 0;
}