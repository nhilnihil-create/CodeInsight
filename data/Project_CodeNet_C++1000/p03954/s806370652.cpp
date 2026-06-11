#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[200005],l,r,mid,ans=0;

bool check(){
	int b[200005]={0};
	for(int i=1;i<=n;i++)
	if(a[i]>=mid)b[i]=1;
	else b[i]=0;
	int middle=(n+1)/2;
	int left=middle,right=middle;
	for(int i=0;i<middle;i++){
		if(b[left]==b[left-1]||b[right]==b[right+1])
		return b[left];
		left--;
		right++;
	}
	return b[1];
}

int main(void){
	scanf("%d",&n);
	n=n*2-1;
	l=n;
	r=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		l=min(l,a[i]);
		r=max(r,a[i]);
	}
	while(l<=r){
		mid=(l+r+1)/2;
		if(check())
		l=mid+1,ans=max(ans,mid);
		else r=mid-1;
	}
	printf("%d",ans);
} 