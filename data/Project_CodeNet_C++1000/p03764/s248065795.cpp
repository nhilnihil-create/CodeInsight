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
const int MAXN=2e5+11;
int N,M,X[MAXN],Y[MAXN],Sx[MAXN],Sy[MAXN],Ans1,Ans2;
int Mod(int x){return ((x%mod)+mod)%mod;}
signed main(){
    N=read(),M=read();for(int i=1;i<=N;i++) X[i]=read();for(int i=1;i<=M;i++) Y[i]=read();
    for(int i=N;i>=1;i--) Sx[i]=Sx[i+1]+X[i];for(int i=M;i>=1;i--) Sy[i]=Sy[i+1]+Y[i];
    for(int i=1;i<=N;i++) Ans1+=Mod(Sx[i+1]-X[i]*(N-i)),Ans1%=mod;for(int i=1;i<=M;i++) Ans2+=Mod(Sy[i+1]-Y[i]*(M-i)),Ans2%=mod;
    printf("%lld\n",Ans1*Ans2%mod);return 0;
}

