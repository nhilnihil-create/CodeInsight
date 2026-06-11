#include <iostream>
#include <cstdlib>
#include <cstdio>
#define N 4000011
using namespace std;
int b[N],len,n,a[N],cnt[N],ans,maxx,minn,sum[N];
int judge(int avr){
	b[0]=b[len+1]=-1;
	for(int i=1;i<=len;i++){
		if(a[i]>=avr) b[i]=1;
		else b[i]=0;
		if(b[i]==b[i-1]) cnt[i]=cnt[i-1]+1;
		else cnt[i]=1;
	}
	for(int i=len;i>=1;i--){
		if(b[i]==b[i+1]) sum[i]=sum[i+1]+1;
		else sum[i]=1;
	}
	for(int i=0;i<n;i++){
		if(cnt[n+i]+sum[n+i]-1>=2) return b[n+i];
		if(cnt[n-i]+sum[n+i]-1>=2) return b[n-i];
	}
	return b[1];
}
void bin(){
	int head=minn,tail=maxx,mid;
	while(head<=tail){
		mid=(head+tail)/2;
		if(judge(mid)){
			ans=mid;
			head=mid+1;
		}
		else tail=mid-1;
	}
}
int main(){
//	freopen("triangle.in","r",stdin);
	scanf("%d",&n);len=2*n-1;
	for(int i=1;i<=len;i++) scanf("%d",&a[i]),minn=min(minn,a[i]),maxx=max(maxx,a[i]);
	bin();
	printf("%d",ans);
	return 0;
}