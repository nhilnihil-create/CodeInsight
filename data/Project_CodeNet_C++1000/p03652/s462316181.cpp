#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair

const int MAXN=205;
const ll inf = 1e18;
const ll mod=1e8;

typedef pair<ll, ll> pi;

ll gc(ll a,ll b)
{
    if(b==0) return a;
    return gc(b,a%b);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

vector<bool>prime(100005,true);
vector<ll>v;
void sieve(ll n)
{
    prime[1]=false;
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

    for(int i=2;i<=n;i++)
    {
        if(prime[i]==true)
            v.push_back(i);
    }
}

int BIT[1000];
void update(int x, int delta)
{
    int n;
      for(; x <= n; x += x&-x)
        BIT[x] += delta;
}
int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];
     return sum;
}


inline ll add(ll a,ll b) {return ((a%mod)+(b%mod))%mod;}
inline ll sub(ll a,ll b) {return ((a%mod)-(b%mod)+mod)%mod;}
inline ll mul(ll a,ll b) {return ((a%mod)*(b%mod))%mod;}


ll recur(ll idx,ll sum, vector<pair<ll,ll> >& v, vector<ll>& b, vector<ll>& pre, vector<ll>& dp)
{
    if(idx==b.size()) return 0;
    if(dp[idx]!=-1) return dp[idx];
    ll temp=INT_MAX;
    temp=min(temp,recur(idx+1,sum,v,b,pre,dp) + b[idx]);
    for(int i=0;i<v.size();i++)
    {
        ll x=v[i].first;
        ll y=v[i].second;
        if(idx+x-1>=b.size()) continue;
        ll calc= pre[idx+x-1]-pre[idx+y-1];
        temp=min(temp, recur(idx+x, sum,v,b,pre,dp)+ calc);
    }
    dp[idx]=temp;
    return temp;
}


ll find(ll u, vector<ll>& parent)
{
    if(u==parent[u]) return u;
    else return parent[u]=find(parent[u],parent);
}
 void unio(ll u, ll v, vector<ll>& parent, vector<ll>& ran)
{
    u=find(u,parent);
    v=find(v,parent);
    if(u==v) return;
    if(ran[u]>=ran[v])
    {
        parent[v]=u;
        ran[u]+=ran[v];
    }
    else{
        parent[u]=v;
        ran[v]+=ran[u];
    }
}
ll dfs(ll src, ll p, vector<ll>& a, vector<pair<ll,ll> > adj[], vector<ll>& dp)
{
    ll can1=0;
    ll can2=0;
    vector<pair<ll,ll> >:: iterator it;
    for(it=adj[src].begin();it!=adj[src].end();it++)
    {
        if(((*it).first==p)) continue;
        ll st=max(0LL,dfs((*it).first,src,a,adj,dp)- (*it).second);
        if(st>can1)
        {
            can2=can1;
            can1=st;
        }
        else if(st>can2)
        {
            can2=st;
        }
    }
    dp[src]=a[src]+ can1+can2;
    return (max(can1,can2)+ a[src]);
}
/*  FINDING LCS IN (NLOGN) COMPLEXITY
int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> d(n+1, 1000000000);
	for (int i = 0; i < n; i++) {
		*lower_bound(d.begin(), d.end(), a[i]) = a[i];
	}
	for (int i = 0; i <= n; i++) {
		if (d[i] == 1000000000) {
			cout << i << endl;
			return 0;
		}
	}
*/
struct comp1{
    bool operator ()(pair<ll,ll>& temp1, pair<ll,ll>& temp2)
{

}
};
bool comp2(pair<ll,ll>& temp1, pair<ll,ll>& temp2)
{
    return temp1.second<temp2.second;
}

ll getinv(ll temp)
{
    return power(temp,mod-2,mod);

}

int main()
{
    ll n,m;
    cin>>n>>m;
    ll a[n][m];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++) cin>>a[i][j];
    }
    vector<bool>vis(m+1,false);
    ll ans=inf;
    while(true)
    {
    ll ma=0;
    ll which=0;
    vector<ll>cnt(m+1,0);
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(!vis[a[i][j]])
            {
                cnt[a[i][j]]++;
                break;
            }
        }
    }
    for(ll i=1;i<=m;i++)
    {
     if(cnt[i]>ma)
     {
         ma=cnt[i];
         which=i;
     }
    }
    if(ma==0) break;
    ans=min(ans,cnt[which]);
    vis[which]=true;
    }
    cout<<ans;
}
