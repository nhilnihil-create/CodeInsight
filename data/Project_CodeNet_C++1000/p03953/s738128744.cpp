#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100010;
ll k;
int n,m,id[N];
ll x[N];int nxt[N];ll cf[N],ans[N];bool vis[N];int cnt;
void dfs(int st){
	while(!vis[st])
	{
	id[++cnt]=st;
	vis[st]=1;
	st=nxt[st];
//	printf("check_id_id id[%d]:%d\n",cnt,id[cnt]);
    }
    return;
}
int main(){
	///freopen("in.txt","r",stdin);
	//freopen("arbitout.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&x[i]);
    	cf[i]=x[i]-x[i-1];
    	nxt[i]=i;
    //	printf("cf[%d]:%d\n",i,cf[i]);
    }
    scanf("%d%lld",&m,&k);
    for(int i=1;i<=m;i++){
    	int kk;
    	scanf("%d",&kk);
        swap(nxt[kk],nxt[kk+1]);
	 }
	// for(int kk=1;kk<=n;kk++)printf("nxt[%d]:%d\n",kk,nxt[kk]);
	 for(int i=1;i<=n;i++){
	 	if(!vis[i]){
	        cnt=0;
	 		dfs(i);
	 		if(cnt==1) ans[id[1]]=cf[id[1]];
	 		else {
	 		for(int j=1;j<=cnt;j++){
	 		ans[id[j]]=cf[id[(k+j-1)%cnt+1]];
		     }  
	 	}
	    }
	 }
	ll anss=0;
	 for(int i=1;i<=n;i++){
	    anss+=ans[i];
	 //	printf("well_down_cf[%d]:%d,anss:%d  ",i,cf[i],anss);
	 	 printf("%lld.0\n",anss);
	 }
}