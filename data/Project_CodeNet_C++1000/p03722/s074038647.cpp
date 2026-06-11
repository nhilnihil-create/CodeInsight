#include<bits/stdc++.h>
#include<string.h>
 
typedef long long int ll;
#define all(x) (x).begin(), (x).end()
 
using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

ll nxtl(){
    ll x;
    cin>>x;
    return x;
}
 
void SieveOfEratosthenes(int n,vector <int> &primes) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          primes.push_back(p);
} 
 
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
 
ll power(ll x, ll y,ll mod) 
{ 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2,mod); 
    if (y%2 == 0) 
        return (temp*temp)%mod; 
    else
        return (((x*temp)%mod)*temp)%mod; 
}

ll binomialCoeff(ll n, ll k) 
{ 
    ll C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

vector <vector <pair<ll,ll> > > g;
vector <vector <ll> > edges;
set <ll> reach;
vector <vector <ll> > g2;
void bfs(ll s,ll n);

ll BellmanFord(int src,int n,int m) 
{ 
    
    ll dist[n+1]; 
  
    // Step 1: Initialize distances from src to all other vertices 
    // as INFINITE 
    for (int i = 1; i <= n; i++) 
        dist[i] = 1e18; 
    dist[src] = 0; 
  
    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 
    // edges 
    for (int i = 1; i <= n - 1; i++) { 
        for (int j = 0; j < m; j++) { 
            int u = edges[j][0];
            int v = edges[j][1];
            ll weight = edges[j][2];
            if (dist[u] != 1e18 && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 

    //for(int i=1;i<=n;i++)
       // cout<<dist[i]<<" ";
   // cout<<endl;
  
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there 
    // is a cycle. 
    for (int i = 0; i < m; i++) { 
        int u = edges[i][0];
        int v = edges[i][1];
        ll weight = edges[i][2];
        if (dist[u] != 1e18 && dist[u] + weight < dist[v]&&(reach.count(u)||reach.count(v))) { 
            //cout<<u<<" "<<v<<endl;
           return -1;
        } 
    } 
   
  
    return dist[n]; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=nxt(),m=nxt();
    vector <ll> row(3);
    edges.resize(m,row);
    vector <pair<ll,ll>  > r2;
    vector <ll> r3;
    g2.resize(n+1,r3);
    g.resize(n+1,r2);
    for(ll i=0;i<m;i++)
    {
        ll u=nxt(),v=nxt(),c=nxt();
        edges[i][0]=u;edges[i][1]=v;edges[i][2]=-c;
        g[u].push_back({v,-c});
        g2[v].push_back(u);
    }

    bfs(n,n);
    ll ret=BellmanFord(1,n,m);
    if(ret==-1)
        cout<<"inf"<<endl;
    else
        cout<<-ret<<endl;

    
    
    return 0;   
}

void bfs(ll s,ll n)
{
    vector <bool> visited;
    visited.resize(n+1,0);
    visited[s]=1;
    queue <ll> q;
    q.push(s);
    reach.insert(s);
    while(q.size())
    {
        ll x=q.front();
        q.pop();
        for(auto i:g2[x])
            if(!visited[i])
            {
                visited[i]=1;
                q.push(i);
                reach.insert(i);
            }
    }
}




 
 
