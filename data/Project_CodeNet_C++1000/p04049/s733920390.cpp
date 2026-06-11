#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&x){cerr<<x<<endl;}
template<typename T,typename ...S> void _do(T &&x,S &&...t){cerr<<x<<", ";_do(t...);}
template<typename a,typename b> ostream& operator << (ostream &s,const pair<a,b> &p){return s<<"("<<p.X<<","<<p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e)
#endif

vector<int> G[2005];
int dis[2005],k;

void dfs(int u,int f=0,int d=0)
{
    dis[u]=d;
    if(d==k>>1) return;
    for(int i:G[u])
        if(i!=f)
            dfs(i,u,d+1);
}

bool dfs2(int u,int f=0,int d=0)
{
    dis[u]=d;
    if(d>k) return 0;
    for(int i:G[u])
        if(i!=f&&~dis[i])
            if(!dfs2(i,u,d+1))
                return 0;
    return 1;
}

int main()
{
    IOS();
    int n,a,b,ans=0;
    cin >> n >> k;
    for(int i=1;i<n;++i)
        cin >> a >> b,G[a].pb(b),G[b].pb(a);
    if(k&1^1)
        for(int i=1;i<=n;++i)
        {
            FILL(dis,-1);
            dfs(i);
            if(dfs2(max_element(dis+1,dis+n+1)-dis))
            {
                int tmp=0;
                for(int j=1;j<=n;++j)
                    if(~dis[j])
                        ++tmp;
                ans=max(ans,tmp);
            }
        }
    else
        for(int i=1;i<=n;++i)
            for(int j:G[i])
                if(i<j)
                {
                    FILL(dis,-1);
                    dfs(i,j),dfs(j,i);
                    if(dfs2(max_element(dis+1,dis+n+1)-dis))
                    {
                        int tmp=0;
                        for(int r=1;r<=n;++r)
                            if(~dis[r])
                                ++tmp;
                        ans=max(ans,tmp);
                    }
                }
    cout << n-ans << "\n";
}