#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 100000+5;
const int dx[] = {0,0,-1,1,-1,-1,1,1};
const int dy[] = {-1,1,0,0,-1,1,-1,1};
using namespace std;

int x[N];
int dp[N][50];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&x[i]);

    int L,Q;
    scanf("%d%d",&L,&Q);
    for(int i=1; i<=n ;i++){
        int pos=upper_bound(x+1,x+1+n,x[i]+L)-x-1;
        if(x[i]+L>=x[n])
            dp[i][0]=n;
        else
            dp[i][0]=pos;
    }

    for(int i=1; i<=30; i++)
        for(int j=1; j<=n; j++)
            dp[j][i]=dp[dp[j][i-1]][i-1];

    while(Q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(b<a)
            swap(a,b);
        LL res=0;
        for(int i=30; i>=0; i--){
            if(dp[a][i]<b){
                res+=(1<<i);
                a=dp[a][i];
            }
        }
        printf("%lld\n",res+1);
    }
    return 0;
}
