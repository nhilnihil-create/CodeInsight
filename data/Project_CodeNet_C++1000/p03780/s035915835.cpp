#include<cstdio>
#include<algorithm>
using namespace std;
int bag[5005],ans,a[5005],n,k;
void bs(int l,int r,int num) {
	int mid=l+r>>1;
	bag[0]=num;
	for(int i=1;i<=n;++i) {
		if(i==mid) continue;
		for(int j=k-1;j>=0;--j) if(bag[j]==num&&j+a[i]<k) bag[j+a[i]]=num;
	}bool flag=true;
	for(int j=max(0,k-a[mid]);j!=k;++j) if(bag[j]==num) {flag=false;break;}
	if(!flag) ans=mid;if(l==r) return;
	if(!flag) bs(l,mid,num+1);
	else bs(mid+1,r,num+1);
}
int main(){
	scanf("%d%d",&n,&k);ans=n+1;
	for(int i=n;i;--i) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	bs(1,n,1);
	printf("%d",ans-1);
	return 0;
}