/* ***********************************************
Author        :yang12138
Created Time  :2017年04月13日 星期四 01时52分59秒
File Name     :F.cpp
************************************************ */
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int,int>pii;
#define lson (root<<1)
#define rson (root<<1|1)

const int N=1e6+10;
const int mod=1e9+7;
ll dp[N],s[N];

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   	int n;
	scanf("%d",&n);

	dp[0]=1,dp[1]=n,dp[2]=n;
	s[0]=1,s[1]=n+1,s[2]=2*n+1;
	for(int i=3;i<n;i++){
		dp[i]=dp[i-1]+s[i-3];
		dp[i]%=mod;
		s[i]=s[i-1]+dp[i];
		s[i]%=mod;
	}

	ll ans=(n+(s[n-1]-1)*(n-1))%mod;
	printf("%lld\n",ans);

    return 0;
}
