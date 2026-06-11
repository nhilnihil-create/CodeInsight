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
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 100000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
LL x[N],y[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for(int j=1;j<=m;j++)
        scanf("%lld",&y[j]);

    LL sx=0;
    for(int i=1;i<=n;i++){
        sx=(sx+x[i]*(i-1))%MOD;
        sx=(sx-x[i]*(n-i))%MOD;
    }
    LL sy=0;
    for(int i=1;i<=m;i++){
        sy=(sy+y[i]*(i-1))%MOD;
        sy=(sy-y[i]*(m-i))%MOD;
    }
    LL res=(sx*sy)%MOD;
    printf("%lld\n",res);

    return 0;
}
