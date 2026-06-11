#include<bits/stdc++.h>

using namespace std;
#define int long long
#define MAXN 250000
int c[250000];
int lsh[MAXN],cnt,num[MAXN],n,k;

int lowbit(int x){return x&(-x);}

void update(int x){
    for(int i=x;i<=n;i+=lowbit(i))
        c[i]+=1;
}

int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += c[i];
    return ans;
}
signed main(){
	scanf("%lld%lld",&n,&k);
	lsh[0]=0;
	num[0]=0;
	for(int i=1; i<=n; i++) {
		int temp;
		scanf("%lld",&temp);
		num[i]=num[i-1]+temp-k;	
		lsh[i]=num[i];
	}
	sort(lsh+1 , lsh+n+1);
	cnt = unique(lsh+1 , lsh+n+1) - lsh - 1;
	for(int i=0; i<=n; i++)
		num[i] = lower_bound(lsh+1 , lsh+cnt+1 , num[i]) - lsh;
	int ans=0;
	for(int i=0;i<=n;i++){
		ans+=getsum(num[i]);
		update(num[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

