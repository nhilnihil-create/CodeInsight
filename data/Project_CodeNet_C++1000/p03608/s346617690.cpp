#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int>
#define pr(x) cout << x << endl;
using namespace std;

int n,m,r,ans;
int d[210][210];
vector<int> ress;

void solve(vector<int> list, vector<int> vis){
  if(list.size()==r){
    int tmp=0;
    rep(i,r-1){
      //cout << i << endl;
      tmp+=d[list[i]][list[i+1]];
    }
    //cout << tmp << endl;
    ans=min(ans,tmp);
    return;
  }
  rep(i,vis.size()){
    vector<int> nvis=vis;
    vector<int> nlist=list;
    nlist.push_back(ress[nvis[i]]);
    nvis.erase(nvis.begin()+i);
    solve(nlist,nvis);
  }
}

int main(){
  cin >> n >> m >> r;
  rep(i,r){
    int tr; cin >> tr;
    ress.push_back(--tr);
  }
  vector<vector<int> > ki(n);
  int cost[210][210];

  rep(i,m){
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    ki[a].push_back(b);
    ki[b].push_back(a);
    cost[a][b]=cost[b][a]=c;
  }

  rep(i,r-1){
    for(int j=i+1; j<r; j++){
      priority_queue<P> q;
      q.emplace(0,ress[i]);
      vector<int> mc(n,INF);
      mc[ress[i]]=0;
      while(!q.empty()){
        int now=q.top().second;
        int nowc=q.top().first;
        q.pop();
        for(int x : ki[now]){
          int newcost=nowc+cost[now][x];
          if(newcost<mc[x]){
            q.emplace(newcost,x);
            mc[x]=newcost;
          }
        }
      }
      d[ress[i]][ress[j]]=d[ress[j]][ress[i]]=mc[ress[j]];
    }
  }
  ans=INF;
  vector<int> vist(r);
  rep(i,r) vist[i]=i;
  vector<int> emp;
  solve(emp,vist);
  cout << ans << endl;
return 0;
}