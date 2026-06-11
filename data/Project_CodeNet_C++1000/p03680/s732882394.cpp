#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

int bfs(int n,vector<vector<int>> &adj){
    vector<bool> vis(n+1,false);
    queue<int> q;
    vis[1]=true;
    q.push(1);
    int l=0;
    while(!q.empty()){
        int sz=q.size();
        l++;
        while(sz-->0){
            int u=q.front();q.pop();
            // if(u==2){return l;}
            for(int v:adj[u]){
                if(v==2){return l;}
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return -1;
}

void solve(){
    int n;
    cin>>n;
    
    vector<vector<int>> adj(n+1);
    
    for(int u=1;u<=n;u++){
        int v;
        cin>>v;
        adj[u].push_back(v);
    }
    
    cout<<bfs(n,adj)<<endl;
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}