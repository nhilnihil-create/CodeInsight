/*ANKON GHOSH
  KUET,ECE 2K16*/
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define inf 1e18
#define MAX 200005
#define mod 1000000007
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld",&a,&b)
#define sfff(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define Case(i) cout<<"Case #"<<i<<": "
#define pf(a) printf("%lld\n",a)
#define pfsn printf("NO\n")
#define pfs  printf("YES\n")
#define pff(a,b) printf("%lld %lld\n",a,b)
#define pfff(a,b,c) printf("%lld %lld %lld\n",a,b,c)
#define pffff(a,b,c,d) printf("%lld %lld %lld %lld\n",a,b,c,d)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define FOR1(i,n) for(ll i=1;i<=n;i++)
#define LOOP(x,y) for(ll r=x;r<=y;r++)
#define RFOR(i,n) for(ll i=n-1;i>=0;i--)
#define RFOR1(i,n) for(ll i=n;i>0;i--)
#define RLOOP(x,y) for(ll i=y;i>=x;i--)
#define m_p(a,b) make_pair(a,b)
#define p_b(a) push_back(a)
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
map<ll,ll>mp1,mp;
vector<pair<ll,pair<ll,ll> > >vpp,vpp1;
vector<pair<ll,ll> >vp,fin;
vector<ll>v,v1,v2,dummy;
map<pair<ll,ll>,bool>mbb;
map<ll,bool>mb;
ll n,k,a,b,c,d,ta,sum=0,cnt=0,m,l,req,sz,maxi;
bool sortbysec(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)
{
    return (a.second < b.second);
}
vector<pair<ll,ll> >adj[MAX+10];
ll dep[MAX+10];
void reset()
{
    FOR(i,MAX)
    {
        adj[i].clear();
    }
    memset(dep,inf,sizeof dep);
}
void dijkstra(ll s)
{
    priority_queue<pair<ll,ll> >q;
    q.push(m_p(0,s));
    dep[s]=0;
    while(!q.empty())
    {
        ll cost=-q.top().ff;
        ll node=q.top().ss;
        q.pop();
        ll l=adj[node].size();
        FOR(i,l)
        {
            ll present_node=adj[node][i].ss;
            ll fcost=adj[node][i].ff;
            if(dep[present_node]>cost+fcost)
            {
                dep[present_node]=cost+fcost;
                q.push(m_p(-dep[present_node],present_node));
            }
        }
    }
}
int main()
{
    fast;
    reset();
    cin>>n;
    FOR(i,n-1)
    {
        ll x,y;
        cin>>x>>y>>c;
        adj[x].p_b(m_p(c,y));
        adj[y].p_b(m_p(c,x));
    }
    ll Q;
    cin>>Q>>k;
    dijkstra(k);
    FOR(i,Q)
    {
        cin>>a>>b;
        cout<<dep[a]+dep[b]<<endl;
    }
    return 0;
}
