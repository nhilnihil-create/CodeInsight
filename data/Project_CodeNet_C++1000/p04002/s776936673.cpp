#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

const int N=1e5+5;

ll x,y,h,w,n;
ll ans[15],node[N<<4],tot; 

int main(){ 
	scanf("%lld%lld%lld",&h,&w,&n);
	ll zero=(h-2)*(w-2);
	while(n--){
		scanf("%lld%lld",&x,&y);
		for(ll i=0;i<3;i++)
			for(ll j=0;j<3;j++)
				if(1<=x-i&&x-i<=h-2&&1<=y-j&&y-j<=w-2) node[tot++]=mod*(x-i)+(y-j);
	} 
	sort(node,node+tot);
	for(int i=0,cnt=1;i<tot;i++)
		if(node[i]==node[i+1]) cnt++;
		else ans[cnt]++,cnt=1,zero--; 
	printf("%lld\n",zero);
	for(int i=1;i<=9;i++) printf("%lld\n",ans[i]); 
	return 0; 
}
