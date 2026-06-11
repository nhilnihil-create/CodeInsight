#include <bits/stdc++.h>
using namespace std;

//repetition
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

//container util
#define all(x) (x).begin(),(x).end()

//typedef
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

//const value
//const ll MOD = 1e9 + 7;
//const int dx[] = {0,1,0,-1};//{0,0,1,1,1,-1,-1,-1};
//const int dy[] = {1,0,-1,0};//{1,-1,0,1,-1,0,1,-1};

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
inline ll toLL(string s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

VI edge[(int)1e5+2];
bool used[(int)1e5];
deque<int> ans;

void dfs(int current, bool backFlag){
  for(int node : edge[current]){
    if(used[node]) continue;
    used[node] = true;
    if(backFlag) ans.push_back(node);
    else ans.push_front(node);
    dfs(node,backFlag);
    break;
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  int a,b;
  rep(i,m){
    cin >> a >> b;
    a--, b--;
    edge[a].push_back(b);
    edge[b].push_back(a);

  }
  // a,b には最後に追加された辺が格納されている
  used[a] = true, used[b] = true;
  ans.push_front(a);
  dfs(a,false);
  ans.push_back(b);
  dfs(b,true);
  cout << ans.size() << endl;
  while(ans.empty() == false){
    int node = ans.front();
    ans.pop_front();
    if(ans.empty()) cout << node+1 << endl;
    else cout << node+1 << " ";
  }

  return 0;
}
