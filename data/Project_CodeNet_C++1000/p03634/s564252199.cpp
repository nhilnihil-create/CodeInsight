#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll>pa;

const int N=2e5+100;
const int mod=1e9+7;
vector<pa>ve[N];
int n;
ll vis[N];
queue<pa>q;
void bfs(int k)
{
    memset(vis,-1,sizeof vis);
    vis[k]=0;
    q.push(make_pair(k,0));
    while(q.size()){
        pa kk=q.front();q.pop();
        for(auto v:ve[kk.first]){
            if(vis[v.first]==-1){
                q.push(v);
                vis[v.first]=vis[kk.first]+v.second;
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(0);cin.tie(0);
   cin>>n;
   for(int i=1;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    ve[a].push_back(make_pair(b,c));
    ve[b].push_back(make_pair(a,c));
   }
   int qq,k;
   cin>>qq>>k;
   bfs(k);
   while(qq--){
     int x,y;
     cin>>x>>y;
     cout<<vis[x]+vis[y]<<endl;
   }
   return 0;
}

