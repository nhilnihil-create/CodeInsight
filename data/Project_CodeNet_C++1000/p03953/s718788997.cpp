#include<bits/stdc++.h>

using namespace std;

const int N=100005;
int n,m,p[N],a[N],r[N],tmp[N];
long long k;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++)a[i]=r[i]=i;
	scanf("%d%lld",&m,&k);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),swap(a[x-1],a[x]);
	while(k){
		if(k&1)for(int i=1;i<n;i++)r[i]=a[r[i]];
		for(int i=1;i<n;i++)tmp[i]=a[a[i]];memcpy(a,tmp,n<<2);k>>=1;
	}
	long long x=p[1];
	for(int i=1;i<=n;i++)printf("%lld.0\n",x),x+=p[r[i]+1]-p[r[i]];
	return 0;
}