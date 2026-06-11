#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+50;
int n,ans=0,a[N],q[N],id[N],head=0;
int l[N],r[N];
signed main(){
	scanf("%lld",&n);
	rep(i,1,n) scanf("%lld",&a[i]);
	q[++head]=a[1]; id[head]=1; l[1]=0;
	rep(i,2,n) { //递增 
		if(a[i]>q[head]){
			q[++head]=a[i];
			id[head]=i;
		}
		else {
			while(q[head]>=a[i]) r[id[head]]=i,head--;
			if(id[head]) l[i]=id[head];
			else l[i]=0;  
			q[++head]=a[i];
			id[head]=i;
		}
	}
	head=0;
	memset(q,0,sizeof(q)); memset(id,0,sizeof(id));
	q[++head]=a[n]; id[head]=n; r[n]=n+1;
	for(int i=n-1;i>=1;i--){
		if(a[i]>q[head]){
			q[++head]=a[i];
			id[head]=i;
		}
		else{
			while(q[head]>=a[i]) l[id[head]]=i,head--;
			if(id[head]) r[i]=id[head];
			else r[i]=n+1;
			q[++head]=a[i];
			id[head]=i;
		}
	}
	rep(i,1,n) ans+=a[i]*(i-l[i])*(r[i]-i);
	printf("%lld\n",ans); 
	return 0;
}
