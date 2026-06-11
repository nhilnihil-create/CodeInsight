#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

vector<P> vec[110000];
int k;
ll d[110000];

void dfs(int p){
  for(P x : vec[p]){
    if(d[x.first] != 0 || x.first == k-1) continue;
    d[x.first] = d[p] + x.second;
    dfs(x.first);
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    vec[a].push_back(P(b, c));
    vec[b].push_back(P(a, c));
  }
  int q;
  cin >> q >> k;
  d[k-1] = 0;
  dfs(k-1);
  for(int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    cout << d[x] + d[y] <<endl;
  }
}
  