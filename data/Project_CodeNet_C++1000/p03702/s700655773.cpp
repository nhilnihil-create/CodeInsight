#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1e9+7;
ll MOD = 998244353;
typedef pair<ll,ll> ii;
#define iii pair<ii,ll>
#define f(i,a,b) for(long long i = a;i < b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define w(t) while(t--)
#define c(n); cin>>n;
#define p(n) cout<<n;
#define pl(n) cout<<n<<endl;
#define ps(n); cout<<n<<" ";
#define F first
#define S second
#define pb(a) push_back(a)
#define all(x) (x).begin(), (x).end()
#define ull unsigned long long
#define vll vector<ll>
#define vii vector<ii>
#define mkp make_pair
#define ld long double
#define arrin(a,n) f(i,0,n){cin>>a[i];}
#define arrout(a,n) f(i,0,n){cout<<a[i]<<" ";}
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
#define PI (2*acos(0))
const long long N = 1e6+5;
vll visit,dist,taken;
vector<vll> adj;
vector<vii> adj2;
priority_queue<ii,vector<ii>, greater<ii> > pq;
ll bit[N]={0};
ll siz;
ll res = 0;
ll lcm(ll a,ll b){return (a * b) / __gcd(a,b);}
ll gcd(ll a,ll b){return __gcd(a,b);}
ll power(ll a,ll b){if(b == 0)return 1;if(b == 1)return a;ll ans = power(a,b/2) % MOD;ans *= ans;ans %= MOD;if(b % 2 == 1)ans *= a;return ans%MOD;}
ll inverse(ll x){x%=MOD;return power(x,MOD-2);}
void BITup(ll k, ll x){while(k <= siz){bit[k]+=x;k += k & -k;}}
ll BITq(ll k){ll s=0;while(k>=1){s+=bit[k];k -= k &-k;}return s;}
struct node{ll lazy,val;}seg[4000000];
struct point{ll x,y;};
void dfs(ll v){visit[v] = 1;for(auto x:adj[v]){if(!visit[x])dfs(x);}}
void bfs(ll s){visit[s] = 1;queue<ll>q;q.push(s);while(!q.empty()){ll u = q.front();ps(u);q.pop();for(auto x:adj[u]){if(!visit[x]){visit[x] = 1;q.push(x);}}}}
void dijkstra(ll s){pq.push(ii(0,s));dist[s] = 0;while(!pq.empty()){ii f = pq.top();pq.pop();ll w = f.F;ll u = f.S;if(w > dist[u]){continue;}for(auto v:adj2[u]){if(dist[u] + v.S < dist[v.F]){dist[v.F] = dist[u] + v.S;pq.push(ii(dist[v.F],v.F));}}}}
void prim(ll edge) {taken[edge] = 1;for(auto v:adj2[edge]) {if (taken[v.first]==0)pq.push(ii(v.second, v.first));}}
ll mst(ll s){taken.assign(N, 0);prim(s);ll cost = 0;while(!pq.empty()){ii front = pq.top();pq.pop();ll w = front.first;ll u = front.second;if(taken[u]==0)cost += w;prim(u);}return cost;}
void YESNO(ll a){if(a){pl("YES");}else{pl("NO");}}
void filesin(void){freopen("tracing.in","r",stdin);}
void filesout(void){freopen("tracing.out","w",stdout);}
///I hope I will get uprating and don't make mistakes
///I will never stop programming
///sqrt(-1) Love C++
///Please don't hack me
///@TheofanisOrfanou Theo830
///Training
ll a,b;
ll arr[100005];
bool check(ll idx,ll n){
    ll thelo = 0;
    ll wa[n];
    f(i,0,n){
        wa[i] = arr[i]  - idx * b;
        if(wa[i] > 0){
            thelo += (wa[i] + a - b - 1) / (a - b);
        }
    }
    return (thelo <= idx);
}
int main(void){
    fastio;
    ll n;
    c(n);
    cin>>a>>b;
    arrin(arr,n);
    ll l = 0,r = 1e9;
    ll ans = INF;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid,n)){
            r = mid - 1;
            ans = min(ans,mid);
        }
        else{
            l = mid + 1;
        }
    }
    pl(ans);
}
