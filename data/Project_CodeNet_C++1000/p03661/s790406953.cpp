#include <bits/stdc++.h>
 
#define N 200009
 
using namespace std;
 
int a[N];

int main(){
	int i,j,t1,t2,t3,t4,n;
	long long int sum,ans,buf1,buf2,buf3,buf4;
	sum=buf2=0;
	ans=1e18;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	buf1=sum;
	for(i=0;i<n-1;i++){
		buf2+=a[i];
		buf1-=a[i];
		buf3=abs(buf1-buf2);
		ans=min(ans,buf3);
	}
	printf("%lld\n",ans);
	return 0;		
}