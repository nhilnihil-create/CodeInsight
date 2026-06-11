#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799;


struct edge{
  int to;
  ll cost;
};

ll dist[100001];
vector<edge> ed[100001];

void dfs(int p, int x){//属性、親、自分
  for(edge e : ed[x]){
    if(e.to == p) continue;
    else{
      dist[e.to] = dist[x] + e.cost;
      dfs(x, e.to);
    }
  }
}

int main(){
  int n;
  cin >> n;
  rep(i, n-1){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    edge p = {b, c}, q = {a, c};
    ed[a].push_back(edge(p));
    ed[b].push_back(edge(q));

  }

  int q, k;
  cin >> q >> k;
  for(int i = 0; i < ed[k].size(); i++){
    dist[ed[k][i].to] = ed[k][i].cost;
    dfs(k, ed[k][i].to);
  }
  for(int i = 1; i <= q; i++){
    int x, y;
    cin >> x >> y;
    cout << dist[x] + dist[y] <<endl;
  }
}