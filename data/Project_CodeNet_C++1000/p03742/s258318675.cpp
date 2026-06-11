#include       <set>
#include       <map>
#include     <queue>
#include     <cmath>
#include    <cstdio>
#include    <cctype>
#include    <vector>
#include   <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const double eps = 1e-7;
const int maxn = 5e6+5;

ll fast_pow(ll a,ll b,ll mod){
    ll ans = 1;
    while(b){
        if(b&1)
            ans = ans*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ans;
}
int S[105][105];
int SG(int x,int y){
    if(x>y)swap(x,y);
    if(S[x][y]!=-1)return S[x][y];

    for(int i=2;i<=x;i+=2){
        if(SG(x-i,y+i/2)==0)
            return S[x][y] = 1;
    }
    for(int i=2;i<=y;i+=2){
        if(SG(x+i/2,y-i)==0)
            return S[x][y] = 1;
    }
    return S[x][y] = 0;
}
int main(){
    /*
    memset(S,-1,sizeof(S));
    S[0][0] = S[0][1] = S[1][0] = S[1][1] = 0;
    for(int i=1;i<=60;i++)
    for(int j=1;j<=60;j++)
        SG(i,j);
    for(int j=0;j<=15;j++){
        for(int i=0;i<=j;i++)
            printf("SG[%d][%d]=%d ",i,j,S[i][j]);
        puts("");
    }
    */
    ll x, y;
    scanf("%lld%lld",&x,&y);
    ll t = x-y;
    if(t<0)t=-t;
    printf("%s\n",(t<=1?"Brown":"Alice"));
    return 0;
}

