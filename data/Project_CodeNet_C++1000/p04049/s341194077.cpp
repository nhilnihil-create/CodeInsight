#include <bits/stdc++.h>
#define F(i,j,k) for(int i=(j);i<=(k);++i)
#define D(i,j,k) for(int i=(j);i>=(k);--i)
#define rep(it,s) for(auto it=s.begin();it!=s.end();++it)
#define Rep(a,s) for(auto a:s)
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class Type>inline ll quick_pow(Type x,Type y,Type MOD){
   ll res=1;
   while(y){
      if(y&1)res=res*x%MOD;
      x=x*x%MOD,y>>=1;
   }
   return res;
}
template<class Type>inline ll inv(Type x,Type MOD){return quick_pow(x,MOD-2);}
template<class Type>inline void read(Type &x){
   x=0;static int f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
   x*=f;
}
const int N=2005;
const int INF=0x3f3f3f3f;
int n,K,root,dep[N],res,_res,__res,ans=INF;
vector<int>E[N];
inline void add(int x,int y){
    E[x].PB(y),E[y].PB(x);
}
void dfs(int x,int f){
    dep[x]=dep[f]+1;
    if(dep[x]-dep[root]>K/2)++res;
    if(dep[x]-dep[root]==K/2+1)++__res;
    Rep(y,E[x]){
        if(y==f)continue;
        dfs(y,x);
    }
    if(dep[x]==dep[root]+1){
        _res=max(_res,__res);
        __res=0;
    }
}
int main(){
   #ifndef ONLINE_JUDGE
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
   #endif
   read(n),read(K);
   int tx,ty;
   F(i,1,n-1){
       read(tx),read(ty);
       add(tx,ty);
   }
   F(i,1,n){
       res=0,_res=0;
       dfs(root=i,0);
       if(K&1)ans=min(ans,res-_res);
       else ans=min(ans,res);
   }
   cout<<ans<<endl;
   return 0;
}
