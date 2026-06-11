#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define pf push_front
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
const int n_max=1e5+5;
vector<int> g[n_max];
bool used[n_max];
deque<int>  deq;

void dfsf(int v){
  for(auto i:g[v]){
    if(used[i]) continue;
    else{
      used[i]=true;
      deq.pf(i);
      dfsf(i);
      break;
    }
  }
}
void dfsb(int v){
  for(auto i:g[v]){
    if(used[i]) continue;
    else{
      used[i]=true;
      deq.pb(i);
      dfsb(i);
      break;
    }
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;  
  //  vector<int> g[n];
  int a,b;
  rep(i,m){
    cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  deq.pf(0);
  deq.pb(g[0][0]);
  //  bool used[n];
  rep(i,n) used[i]=false;
  used[0]=used[g[0][0]]=true;
  dfsf(0);
  dfsb(g[0][0]);
  cout << deq.size() << endl;
  rep(i,deq.size()){
    cout << deq[i]+1 << " ";    
  }
  cout << "" << endl;
  
  
  return 0;
    

}
