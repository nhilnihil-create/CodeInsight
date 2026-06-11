#include <bits/stdc++.h>
#include <vector>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 200005
#define MOD 1000000007
#define INF 1000000000000000000
#define EPS 0.0000000001
#define CHAINS 18
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
bool possible[MAX];
int balls[MAX];
int main()
{
    int n,m,i,u,v;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        balls[i]=1;
    }
    possible[1]=true;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);
        possible[v]=(possible[v]||possible[u]);
        balls[u]--;
        balls[v]++;
        if(possible[u]&&balls[u]==0)
        {
            possible[u]=false;
        }
    }
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(possible[i]) ans++;
    }
    printf("%d",ans);
    return 0;
}
