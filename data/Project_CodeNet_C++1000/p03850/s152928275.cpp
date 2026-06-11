#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
#include<iomanip>
using namespace std;

const int N=1e5+5;
int n;
long long tot,cur,ans;
int a[N],o[N];
long long suf[N],sum[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c;
		if(i!=1) scanf(" %c",&c);
		if(c=='+'||i==1) o[i]=1;
		else o[i]=0;
		scanf("%d",a+i);
	}
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1];
		sum[i]=sum[i+1]+1ll*a[i];
		tot+=1ll*a[i];
		if(!o[i]){
			suf[i]+=tot;
			tot=0;
			ans-=a[i];
		}else ans+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(o[i]) cur+=1ll*a[i];
		else cur-=1ll*a[i];
		if(o[i]==0) ans=max(ans,cur+suf[i+1]-(sum[i+1]-suf[i+1]));
	}
	printf("%lld\n",ans);
	return 0;
}