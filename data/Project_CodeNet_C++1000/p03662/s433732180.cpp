#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
vvi adj;

struct Tree{
    ll n, l;
    vvi adj;
    ll timer;
    vi tin, tout, dist;
    vvi up;

    Tree() {}

    Tree(vvi Adj){
        n = Adj.size();
        adj = Adj;
        preprocess(0);
    }

    void dfs(ll v, ll p)
    {
        if(v!=p){
            dist[v]=dist[p]+1;
        }
        tin[v] = ++timer;
        up[v][0] = p;
        for (ll i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (ll u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(ll u, ll v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    void preprocess(ll root) {
        dist.resize(n);
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vi(l + 1));
        dfs(root, root);
    }

    ll lca(ll u, ll v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (ll i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }

    ll distance(ll u, ll v){
        return dist[u] + dist[v] - 2*dist[lca(u,v)];
    }

    ll distance(ll u){
        return dist[u];
    }

};

struct DSU
{
    int n,x;
    vi p,r,sz;
    DSU(int N)
    {
        n=N;
        x=N-1;
        sz.assign(N,1);
        p.assign(N,0);
        r.assign(N,1);
        for(int i=0;i<N;i++)
            p[i]=i;
    }
    int findset(int i)
    {
        return (p[i]==i)?i:(p[i]=findset(p[i]));
    }
    bool issameset(int i,int j)
    {
        return findset(i)==findset(j);
    }
    void unionset(int i,int j)
    {
        int p1=findset(i);
        int p2=findset(j);
        if(p1!=p2)
        {
            x--;
            if(r[p1]>=r[p2])
            {
                p[p2]=p1;
                sz[p1]+=sz[p2];
                if(r[p1]==r[p2])
                    r[p1]++;
            }
            else
            {
                p[p1]=p2;
                sz[p2]+=sz[p1];
            }
        }
    }
    void disp()
    {
        for(int i=0;i<n;i++)
            cout<<p[i]<<' ';
        cout<<endl;
    }

    int getsize(int i){
        return sz[findset(i)];
    }
    int noofdisjointsets(){
        return x;
    }

};

vii edj;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z;
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n-1;i++){
        cin>>x>>y,x--,y--;
        adj[x].pb(y);
        adj[y].pb(x);
        if(x>y)swap(x,y);
        edj.pb(mp(x,y));
    }
    Tree tree(adj);
    x = tree.distance(n-1);
    y = (x-1)/2;
    x = n-1;
    for(int i=0;i<y;i++){
        x = tree.up[x][0];
    }
    ii br = mp(x,tree.up[x][0]);
    if(br.F>br.S)swap(br.F,br.S);
    DSU ss(n);
    for(auto it:edj){
        if(it!=br){
            ss.unionset(it.F,it.S);
        }
    }
    if(ss.getsize(0)>ss.getsize(n-1)){
        cout<<"Fennec";
    }
    else{
        cout<<"Snuke";
    }

    



    return 0;
}