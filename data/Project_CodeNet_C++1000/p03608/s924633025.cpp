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
int cost[210][210];
vector<int> ress;
 
void solve(vector<int> list, vector<int> vis){
  if(list.size()==r){
    int tmp=0;
    rep(i,r-1){
      //cout << i << endl;
      tmp+=cost[list[i]][list[i+1]];
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
  rep(i,210)rep(j,210){
    cost[i][j]=INF;
    if(i==j) cost[i][j]=0;
  }
 
  rep(i,m){
    int a,b,c; cin >> a >> b >> c;
    a--; b--;
    ki[a].push_back(b);
    ki[b].push_back(a);
    cost[a][b]=cost[b][a]=c;
  }
  rep(i,n)rep(j,n)rep(k,n) cost[j][k]=min(cost[j][k],cost[j][i]+cost[i][k]);

  ans=INF;
  vector<int> vist(r);
  rep(i,r) vist[i]=i;
  vector<int> emp;
  solve(emp,vist);
  cout << ans << endl;
return 0;
}