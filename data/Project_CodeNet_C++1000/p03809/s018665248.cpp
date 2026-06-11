    #include<cstdio>
    #include<cstring>
    #include<cstdlib>
    #include<algorithm>
     
    using namespace std;
     
    typedef long long LL;
    const int MX=200011;
     
    int n;
    LL a[MX];
    struct Edge{int t,nxt;Edge(int _t=0,int _nxt=0):t(_t),nxt(_nxt){}}e[MX];
    int hed[MX],ec,D[MX];
    inline void ade(int f,int t){e[++ec]=Edge(t,hed[f]),hed[f]=ec;}
    LL clca[MX],cf[MX];
     
    #define FE(i) for(int (i)=hed[k];i;i=e[i].nxt)if(e[i].t!=f)
    void dfs(int k,int f){
    	if(D[k]==1){clca[k]=0,cf[k]=a[k];return;}
    	LL S=0,mxs=0;
    	FE(i)dfs(e[i].t,k),S+=cf[e[i].t],mxs=max(mxs,cf[e[i].t]);
    	cf[k]=2*a[k]-S;
    	clca[k]=S-a[k];
    	if(cf[k]<0||clca[k]<0)exit((puts("NO"),0));
    	if(S-mxs<clca[k])exit((puts("NO"),0));
    }
    int main(){
    	scanf("%d",&n);
    	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    	for(int i=1;i<n;i++){
    		static int u,v;scanf("%d%d",&u,&v);
    		ade(u,v),ade(v,u),++D[u],++D[v];
    	}
    	if(n==1)return puts(a[1]?"NO":"YES"),0;
    	if(n==2)return puts(a[1]==a[2]?"YES":"NO"),0;
    	int rot=0;
    	for(int i=1;i<=n;i++)if(D[i]>1){rot=i;break;}
    	dfs(rot,0);
    	if(cf[rot])return puts("NO"),0;
    	puts("YES");
    	return 0;
    }