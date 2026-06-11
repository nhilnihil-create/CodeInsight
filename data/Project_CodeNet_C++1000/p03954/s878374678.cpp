#include<bits/stdc++.h>
using namespace std;
const int maxn=200003;
int n,a[maxn];
bool b[maxn];
#define v(i) (a[i]>=x)
bool check(int x){
	int mid=(n+1)>>1,ans=maxn,ret=-1;
	for(int i=1,j=1;i<=n;i++){
		for(;j<=n&&v(i)==v(j);j++);
		if(i+1==j)continue;
		int tmp=min(abs(mid-i),abs(j-1-mid));
		if(tmp<ans)ans=tmp,ret=v(i);
	}
	return ~ret?ret:v(1);
}
int main(){
	scanf("%d",&n);
	n=(n<<1)-1;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	int l=1,r=n,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}