#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const int INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const int MOD = 1000000007;
const int MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;



ll n,a[100010];
ll depth[100010];
vll I[101010];
ll cost[101010];
bool used[101010];
vector<ll> G[100010],H[100010];
ll cnttrue[100010]={};

void dfs(ll s){
    if(cnttrue[s]!=G[s].size()){
        for(auto i : G[s]){
            dfs(i);
        }
    }
    sort(all(I[s]));
    reverse(all(I[s]));
    rep(i,I[s].size()){
        cost[s]=max(cost[s],i+1+I[s][i]);
    }
    for(auto i:H[s]){
        I[i].push_back(cost[s]);
    }
    return ;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    depth[1]=0;
    cin>>n;
    rep(i,n-1){
        cin>>a[i];
        H[i+2].push_back(a[i]);
        G[a[i]].push_back(i+2);
    }
    ll maxd=0;
    queue<ll> que,q;
    que.push(1);
    while(!que.empty()){
        ll s=que.front();
        que.pop();
        for(auto i :G[s]){
            depth[i]=depth[s]+1;
            maxd=max(depth[i],maxd);
            que.push(i);
        }
    }
    rep2(i,1,n+1){
        depth[i]=maxd-depth[i];
    }
    dfs(1);
    cout<<cost[1]<<endl;
    return 0;
}