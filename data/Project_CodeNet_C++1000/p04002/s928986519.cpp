#include<bits/stdc++.h>
#define N 100007
using namespace std;
int n,h,w,n0,tot=0,a,b;
long long cnt[20],mul=int(1e9)+7,mp[N<<5];
int main(){
	scanf("%d%d%d",&h,&w,&n);
	cnt[0]=1ll*(w-2)*(h-2);
	while(n--){
		scanf("%d%d",&a,&b);
		for(int j=0;j<3;++j)for(int k=0;k<3;++k)
			if(a-j>=1&&a-j<=h-2&&b-k>=1&&b-k<=w-2)mp[tot++]=mul*(a-j)+(b-k);
	}
	sort(mp,mp+tot);
	for(int tmp=1,i=0;i<tot;++i){
		if(mp[i]==mp[i+1])++tmp;
		else ++cnt[tmp],tmp=1,--cnt[0];
	}
	for(int i=0;i<=9;++i)printf("%lld\n",cnt[i]);
	return 0;
}