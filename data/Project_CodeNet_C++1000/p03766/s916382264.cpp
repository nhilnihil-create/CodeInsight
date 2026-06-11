#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<bitset>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long
#define mod 1000000007
using namespace std;
inline int read(){
    int f=1,ans=0;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return f*ans;
}
const int MAXN=1e6+11;
int f[MAXN],N;
signed main(){
    N=read();f[N]=N,f[N-1]=N*N,f[N-1]%=mod;int s=0;
    for(int i=N-2;i>=1;i--){
        s+=f[i+3];s%=mod;
        f[i]+=f[i+1],f[i]%=mod;
        f[i]+=s+(N-1)*(N-1)+i+1,f[i]%=mod;
    }printf("%lld\n",f[1]);return 0;
}
