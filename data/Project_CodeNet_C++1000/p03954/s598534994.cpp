#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=2e5+5;
int n,a[MN],b[MN];
inline bool check(int x){
	for(reg int i=1;i<=n;i++)b[i]=(a[i]>=x);
	reg int lt=-1,rt=-1;
	for(reg int i=(n+1)/2;i>1;i--)
		if(b[i]==b[i-1]){lt=i;break;}
	for(reg int i=(n+1)/2;i<n;i++)
		if(b[i]==b[i+1]){rt=i;break;}
	if(lt<0&&rt<0)return b[1];
	if(lt<0)return b[rt];
	if(rt<0)return b[lt];
	if((n+1)/2-lt<rt-(n+1)/2)return b[lt];
	else return b[rt];
}
int main(){
	scanf("%d",&n);n=2*n-1;
	for(reg int i=1;i<=n;i++)scanf("%d",a+i);
	reg int l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r>>1);
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}