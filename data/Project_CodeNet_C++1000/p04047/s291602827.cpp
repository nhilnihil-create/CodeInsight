#include <bits/stdc++.h>
#define F(i,j,k) for(int i=(j);i<=(k);++i)
#define _F(i,j,k) for(int i=(j);i<(k);++i)
#define D(i,j,k) for(int i=(j);i>=(k);--i)
#define _D(i,j,k) for(int i=(j);i>(k);--i)
#define rep(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();++it)
#define Rep(a,s) for(auto a:s)
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
template<class Type>ll quick_pow(Type x,Type y,Type Mod){
    ll res=1;
    while(y){
        if(y&1)res=res*x%Mod;
        x=x*x%Mod,y>>=1;
    }
    return res;
}
template<class Type>ll inv(Type x,Type Mod){return quick(x,Mod-2,Mod);}
namespace IO{
    template <class T>
    inline void read(T &x){
        x=0;int f=1;char ch=getchar();
        while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
        while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
        x*=f;
    }
};
using namespace IO;
const int N=205;
int n,a[N],dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    read(n);
    F(i,1,2*n)read(a[i]);
    sort(a+1,a+2*n+1);
    memset(dp,-0x3f,sizeof(dp));
    dp[2*n+1][0]=0;
    D(i,2*n,1){
        F(j,0,n-1)dp[i][j]=max(dp[i][j],dp[i+1][j+1]+a[i]);
        F(j,1,n)dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
    }
    cout<<dp[1][0]<<endl;
	return 0;
}
