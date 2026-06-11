#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000

vector<int> tree[100005];

int dfs(int v, int from){
  if(tree[v].size()==1 && from != -1) return 0;
  int ret = 0;
  for(auto to : tree[v]) if(to != from) ret ^= dfs(to, v)+1;
  return ret;
}

int main(){
  int n;
  cin>>n;
  rep(i,n-1){
    int a,b;
    cin>>a>>b;
    a--;b--;
    tree[a].pb(b);
    tree[b].pb(a);
  }

  if(dfs(0,-1) == 0) cout << "Bob" << endl;
  else cout << "Alice" << endl;

  return 0;
}
