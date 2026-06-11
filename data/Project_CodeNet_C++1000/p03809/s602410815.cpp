#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int n,A[N],x,y;
vector<int> G[N];
int dfs(int x,int y){
    if (G[x].size()==1)return A[x];
    int tot=0,x2=0,x1=0,mm,tm=0;
    for (int i=0;i<G[x].size();i++)
		if (G[x][i]!=y){
	        mm=dfs(G[x][i],x);
    	    tm=max(tm,mm);
        	tot+=mm;
    	}
    x2=tot-A[x];
    x1=A[x]-x2;
    if (x1<0||x2<0||A[x]<tm||(x1>0&&y==-1)){
        puts("NO");
        exit(0);
    }
    return x1;
}
signed main(){
    scanf("%lld",&n);
    for (int i=1;i<=n;i++)scanf("%lld",&A[i]);
    if (n==1){
        puts(A[1]?"NO":"YES");
        return 0;
    }
    for (int i=1;i<n;i++){
        scanf("%lld%lld",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if (n==2)puts(A[1]==A[2]?"YES":"NO");
    else {
        for (int i=1;i<=n;i++)
            if (G[i].size()>1){
                dfs(i,-1);
                break;
            }
        puts("YES");
    }
    return 0;
}