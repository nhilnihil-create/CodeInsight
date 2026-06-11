#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
int k;
ll a[100005],b[100005];

ll get(int bit){
	ll ans=0;
	for(int i=0;i<n;i++){
		if((a[i]|bit)==bit)ans+=b[i];
	}
	return ans;
}

int main(void){
	scanf("%d%d",&n,&k);
	int sum=0;
	ll res=0;
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		res+=b[i];
		sum=sum|a[i];
	}
	if(sum<=k){
		printf("%lld\n",res);
	}else{
		ll ans=get(k);
		for(int i=0;i<30;i++){
			if(k>>i & 1){
				int nbit=0;
				for(int j=0;j<30;j++){
					if((k>>j & 1) && i!=j)nbit+=(1<<j);
					else if(i>j)nbit+=(1<<j);
				}
				ans=max(ans,get(nbit));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}