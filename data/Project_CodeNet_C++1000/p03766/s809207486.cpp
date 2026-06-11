#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
using namespace std;
const int P=1e9+7,maxn=1e6+10;
int n,dp[maxn];
int main(){
    scanf("%d",&n);dp[n]=n;dp[n-1]=1ll*n*n%P;int s=0;
    per(i,n-2,1) dp[i]=(dp[i+1]+1ll*(n-1)*(n-1)+s+i+1)%P,s=(s+dp[i+2])%P;
    printf("%d\n",dp[1]);
    return 0;
}