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
ll solve(ll x,ll y){
    if(x>y)swap(x,y);
    if(y%x==0)return (2*(y/x)-1)*x;
    else return 2*(y/x)*x+solve(y%x,x);
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ll n,x;
    cin>>n>>x;
    cout<<n+solve(x,n-x)<<endl;
	return 0;
}
