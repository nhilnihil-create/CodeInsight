#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <functional>

using namespace std ;

const int eps=1e-6 ;
const int inf=0x3f3f3f3f ;

#define mp make_pair
#define pb push_back
#define first fi
#define second se
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REP(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)

typedef unsigned long long ull ;
typedef long long ll ;

inline int read(){
    char c ;
    int f=1 ;
    while((c=getchar())<'0' || c>'9') if (c=='-') f=-1 ;
    int res=c-'0' ;
    while((c=getchar())>='0' && c<='9') res=res*10+c-'0' ;
    return res*f ;
}

const int N = 110 ; 

int n,m ;
int a[110],b[110],dp[110][110][330] ;

int main(){
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read(),b[i]=read() ;
    for (int i=1;i<=n;i++)
    for (int j=0;j<=i;j++)
    for (int k=0;k<=3*j;k++){
        dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]) ;
        dp[i+1][j+1][k+a[i]-a[1]]=max(dp[i+1][j+1][k+a[i]-a[1]],dp[i][j][k]+b[i]) ;
    }

    int ans=0 ;
    for (int i=0;i<=n;i++)
    for (int j=0;j<=3*i;j++){
        ll W= (ll) a[1]*i+j;
        if (W<=m) ans=max(ans,dp[n+1][i][j]) ;
    }
    printf("%d",ans) ;
    return 0 ;
}