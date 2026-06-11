#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
const ll MOD=998244353;

vector<int> to[101010];
bool visited[101010];
deque<int> ans;

void DFSa(int a){
  visited[a] = true;
  for(int v: to[a]){
    if(!visited[v]){
      ans.push_back(v);
      DFSa(v);
      return;
    }
  }
}

void DFSb(int a){
  visited[a] = true;
  for(int v: to[a]){
    if(!visited[v]){
      ans.push_front(v);
      DFSb(v);
      return;
    }
  }
}
    

int main(){
  int n, m; cin >> n >> m; 
  rep(i, m){
    int a, b; cin >> a >> b;
    a--; b--;
    to[a].push_back(b); to[b].push_back(a);
  }
  ans.push_back(0);
  DFSa(0); DFSb(0);
  cout << ans.size() << endl;
  while(ans.size()){
    cout << ans.front()+1;
    ans.pop_front();
    if(ans.size()) cout << " ";
  }
}