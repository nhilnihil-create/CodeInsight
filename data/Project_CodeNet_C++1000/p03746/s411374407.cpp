#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)

typedef long long ll;
typedef pair<int, string> point;

const int MAXN = 2e5 + 5;

int n, m;
vector <int> E[MAXN];
bool bio[MAXN];
deque <int> sol;

void dfs(int x, bool ok = false){
  for(auto e : E[x]){
    if(!bio[e]){
      bio[e] = true;
      if(!ok) sol.push_back(e);
      else sol.push_front(e);
      dfs(e, ok);
      break;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  REP(i, m){
    int a, b; cin >> a >> b;
    E[a].pb(b); E[b].pb(a);
  }
  sol.push_back(1);
  bio[1] = true;
  dfs(1, 0); dfs(1, 1);
  cout << sz(sol) << "\n";
  for(auto it : sol)
    cout << it << " ";
}
