#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
template<class T>bool chmax(T &a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,T b){if(a>b){a=b;return 1;}return 0;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int inf = 1LL<<60;
const int mod = 1e9 + 7;
const double eps = 1e-9;

/*{
  }*/

int n;
vi es[100000];

int dfs(int v){
  vi u;
  for(int to : es[v]){
    u.emplace_back(dfs(to));
  }

  sort(all(u));
  reverse(all(u));

  int ret = 0;
  rep(i, 0, sz(u)){
    chmax(ret, u[i]+i+1);
  }
  return ret;
}

signed main(){
  cin >> n;
  rep(i, 1, n){
    int a;
    cin >> a;
    a--;
    es[a].emplace_back(i);
  }

  cout << dfs(0) << endl;

  return 0;
}
