#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
ll binpow(ll x,ll y)/* (x^y)%p in O(log y) */{ll res=1;while (y > 0){if(y&1)res=(res*x);y = y>>1;x=(x*x);}return res;}
ll binpowmod(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ull res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpowmod(n,p-2,p);}
ll gcd(ll x,ll y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
bool comp(pair<ll,ll> x,pair<ll,ll> y)
{
    return x.first>y.first;
}
bool comp_pairs_by_s(pair<ll,ll> &x ,pair<ll,ll> &y)
{
    return x.second<y.second;
}
bool isPowerOfTwo (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}

class cmp      //comparator for priority_queue 
{               //declaration: priority_queue<int,vector<int>,cmp>
public:         
    bool operator()(pair<int,int> A,pair<int,int> B)
    {
        if(abs(A.first-A.second)==abs(B.first-B.second))
            return A.first>B.first;
        return abs(A.first-A.second)<abs(B.first-B.second);
    }
};
// int prime[10000007]={0};
// void sieve(void)
// {
//  int i,j;
//  for(i=0;i<10000007;i++)
//         prime[i]=1;
//  prime[0]=0,prime[1]=0;
//  for(i=2;i<=sqrt(10000007);i++){
//      if(prime[i]==i){
//          for(j=i*i;j<10000007;j+=i){
//             if(!prime[j])
//                 prime[j]=0;
//          }
//      }
//  }
    
// }
void swap(ll &x,ll &y){
    int temp=x;
    x=y;
    y=temp;
}
  
unsigned int onesComplement(unsigned int n) 
{ 
   // Find number of bits in the given integer 
   int number_of_bits = floor(log2(n))+1; 
  
   // XOR the given integer with poe(2,  
   // number_of_bits-1 and print the result  
   return ((1 << number_of_bits) - 1) ^ n; 
}
vector<pair<int,int>> g[101];
vector<int> dist(101);
vector<int> path(101);
vector<bool> vis(101);
set<pair<int,int>> edges;
void initialize(void){
    for(int i=0;i<101;++i){
        dist[i]=INT_MAX;
        path[i]=i;
        vis[i]=false;
    }
}
void dikstra(int node,int n)
{
    vis[node]=1;
    for(pair<int,int> to: g[node]){
        if(dist[node]+to.second<dist[to.first])
            path[to.first]=node;
        dist[to.first]=min(dist[to.first],dist[node]+to.second); 
    }
    int curdist=INT_MAX;
    int nextnode=-1;
    for(int i=1;i<=n;++i)
        if(!vis[i])
            if(curdist>dist[i]){
                curdist=dist[i];
                nextnode=i;
            }
    if(nextnode!=-1)
        dikstra(nextnode,n);
    return;
}

void solve()
{   
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;++i){
        initialize();
        dist[i]=0;
        dikstra(i,n);
        for(int j=1;j<=n;++j){
            if(j==i) continue;
            int temp=j;
            while(path[temp]!=temp){
                edges.insert({temp,path[temp]});
                temp=path[temp];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(auto to: g[i]){
            if(edges.count({to.first,i}) || edges.count({i,to.first}))
                continue;
            ans++;
        }
    }
    cout<<ans/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}   
