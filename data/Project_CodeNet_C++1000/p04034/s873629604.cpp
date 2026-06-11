#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define mp make_pair
#define F first
#define S second 
#define pl pair<long ,long >
#define pi pair<int ,int >
#define lb(v,x) lower_bound(v.begin(),v.end(),x)-v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x)-v.begin();
#define ct(i) cout<< i << "\n";
#define sv(v) sort(v.begin(),v.end());
#define mod 1000000007
#define M 100005
#define endl "\n"

// std::vector<int> ad[100005];

// int vis[100005]={},intime[100005],low[100005],timer=0;
// int flag=0;
// vector<pair<int,int>> ans;

// void dfs(int node, int par){
//     vis[node]=1;
//     intime[node]=low[node]=timer++;
//     for(auto child:ad[node]){
//         if(child==par) continue;
//         if(vis[child]){
//             low[node] = min(low[node],low[child]);
//             if(intime[child]<intime[node]) ans.pb({node,child});
//         }
//         else{
//             dfs(child,node);
//             if(low[child]>intime[node]){
//                 flag=1;
//                 return;
//             }
//             low[node] = min(low[child],low[node]);
//             ans.pb({node,child});
//         }
//     }
// }

void answer(){
    ll n,m,x,y,ans=0;
    cin>>n>>m;
    int a[n+1],b[n+1];
    for(int i=0;i<=n;i++) a[i]=0,b[i]=1;
    a[1]=1;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(a[x]==1){
            a[y]=1;
        }
        b[x]--;
        b[y]++;
        if (b[x]==0){
            a[x]=0;
        }
    }
    
    for(int i=1;i<=n;i++){
        ans+=a[i];
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    int q;
    //cin>>q; while(q--)
        answer();

    return 0;
}

