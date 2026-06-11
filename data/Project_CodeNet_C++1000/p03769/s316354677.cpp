#include<bits/stdc++.h>
using namespace std;
const int N=65;
long long n;
int m,vi[N],a[205];
int main(){
	scanf("%lld",&n);
	for(;(1LL<<m)-1<=n;m++);

	--m;
	int cnt=m;
	n-=(1LL<<m)-1;
	for(int i=m;~i;i--)
		if(n>>i&1)	vi[i]=1,++cnt;

	int x=cnt;
	printf("%d\n",cnt*2);
	if(vi[0])	printf("%d ",cnt--); 
	for(int i=1;i<=m;i++){
		printf("%d ",i);
		if(vi[i])	printf("%d ",cnt--);
	}
	for(int i=1;i<=x;i++)	printf("%d ",i);
}
