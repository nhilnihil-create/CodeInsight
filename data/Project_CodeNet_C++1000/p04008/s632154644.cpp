#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define mod 1000000000
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define f first
#define ss second
#define pb push_back
#define mp make_pair


vector<int> adj[101010];
int dist[101010], n, k, a[101010], ans=0;
bool vis[101010], ck[101010];

void dfs(int s){
if(vis[s])return ;
vis[s]=true;
for(auto u: adj[s]){
    dist[u]= min(dist[u], dist[s]+1);
    dfs(u);
}
}

void dfs2(int s, int p){

if(ck[s])return ;
ck[s]=true;
for(auto u: adj[s]){
   if(u!=p) dfs2(u, s);
}

}

int main(){

rep(i, 1, 101010)dist[i]=mod;

cin >> n >> k;
rep(i, 1, n){
cin >> a[i];
if(a[1]!=1)a[1]=1, ans++;
adj[a[i]].pb(i);
}
dist[1]=0;
dfs(1);

priority_queue<pi> q;
//vector<pi>  v;
rep(i,1, n){
q.push({dist[i], i});
}

//sort(v.begin(), v.end());

//reverse(v.begin(), v.end());
while(!q.empty()){
int u = q.top().ss;
int d = q.top().f;
q.pop();
if(d<=k)continue;
if(ck[u])continue;
rep(i, 1, k-1){
u = a[u];
}

dfs2(u, a[u]);
ans++;

}

cout << ans << endl;

return 0;}
