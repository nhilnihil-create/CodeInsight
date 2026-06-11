#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
int i,j,k,m,q[211],a[211];
bool cmp(int x,int y){
	return q[x]<q[y];
}
int main(){
	scanf("%lld",&n);n++;
	for (m=1;(1LL<<m)<=n;m++) q[m]=2*m;
	m--;n-=(1LL<<m);
	while (n){
		for (i=0;(1LL<<i)<=n;i++);
		i--;n-=(1LL<<i);q[++m]=2*i+1;
	}
	for (i=1;i<=m;i++) a[i]=i;
	sort(a+1,a+1+m,cmp);
	printf("%d\n",2*m);
	for (i=1;i<=m;i++) printf("%d ",a[i]);
	for (i=1;i<=m;i++) printf("%d ",i);
	puts("");
	return 0;
}