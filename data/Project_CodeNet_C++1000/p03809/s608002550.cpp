#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
// typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 1 << 20;
const lli mod = 998244353;
const lli e3 = 1 << 12;

lli n;
lli a[e5];
vll graph[e5];

void error(lli x=0){
  cerr << x << endl;
  cout << "NO" << endl;
  exit(0);
}

bool is_possible(lli a,lli b){
  if(b-a < 0) return false;
  return true;
}

lli dfs(lli x,lli prev){
  if(graph[x].size() == 1){
    return a[x];
  }else{
    vll mem;
    for(lli y : graph[x]){
      if(y == prev) continue;
      mem.push_back(dfs(y,x));
    }
    lli b = accumulate(mem.begin(),mem.end(),0ll);
    if(!is_possible(a[x],b)) error(1);
    lli b_pair = (b-a[x])*2;
    lli b_above = 2*a[x]-b;
    lli hoge = 0;
    for(lli m : mem){
      hoge += min(m,b_pair/2);
    }
    if(hoge < b_pair) error(2);
    return b_above;
  }
}

int main(){
  cin >> n;
  for(lli i = 1;i <= n;i++) cin >> a[i];
  if(n==2){
    if(a[1]==a[2]) cout << "YES" << endl;
    else error();
    return 0;
  }
  for(lli i = 0;i < n-1;i++){
    lli from,to;
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  lli res_path;
  for(lli i = 1;i <= n;i++){
    if(graph[i].size() > 1){
      res_path = dfs(i,0);
      break;
    }
  }
  if(res_path != 0) error();
  cout << "YES" << endl;

}
