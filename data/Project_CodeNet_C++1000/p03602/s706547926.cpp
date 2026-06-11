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
const int N = 1000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;

LL G[N][N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&G[i][j]);

    bool flag=false;
    LL res=0;
    for(int i=1;i<=n&&!flag;i++){
        for(int j=i+1;j<=n&&!flag;j++){
            bool flag2=false;
            for(int k=1;k<=n&&!flag;k++){
                if(G[i][k]+G[k][j]<G[i][j])
                    flag=true;
                else{
                    if(i!=k&&j!=k&&G[i][j]==G[i][k]+G[k][j])
                        flag2=true;
                }
            }
            if(!flag2)
                res+=G[i][j];
        }
    }

    if(flag)
        printf("-1\n");
    else
        printf("%lld\n",res);

    return 0;
}
