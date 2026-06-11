#include<bits/stdc++.h>
#define N 200005
#define LL long long
using namespace std;
LL val[N];//- + - +
LL suf[N];
int n; 
int main(){
	scanf("%d",&n);
	scanf("%lld",&val[1]);
	int cnt=1;
	for(int i=2,t,last='+';i<=n;i++){
		char ch=getchar();
		while(ch!='+'&&ch!='-') ch=getchar();
		scanf("%d",&t);
		if(ch=='+'&&last=='+') val[cnt]+=t;
		else if(ch!=last) val[++cnt]=t;
		else val[++cnt]=0,val[++cnt]=t;
		last=ch;
	}
	for(int i=cnt;i>=1;i--) suf[i]=suf[i+1]+val[i];
	LL pre=0,ans=-1e18;
	for(int i=1;i<=cnt;i++){
		pre+=val[i]*(i%2==0 ? -1:1);
		if(i%2==0){
			ans=max(ans,pre-val[i+1]+suf[i+2]);
		}
	}
	ans=max(ans,pre);
	cout<<ans<<endl;
	return 0;
}