#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int d[100][100], len[100][100];
int prev[100];
int n, m;

void warshall_floyed(){
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
          

int main(){
  cin >> n >> m;
  rep(i, 100) fill(d[i], d[i] + 100, INF);
  rep(i, 100) fill(len[i], len[i] + 100, INF);
  rep(i, 100) d[i][i] = 0;
  rep(i, m){
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    len[a][b] = c;
    len[b][a] = c;
    d[a][b] = c;
    d[b][a] = c;
  }
  warshall_floyed();
  set<P> s;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k = 0; k < n; k++)
        //i to j で k to j　の辺を通ったか否か
        if(d[i][j] == d[i][k] + len[k][j]){
          if(k < j) s.insert(P(k, j));
          else s.insert(P(j, k));
        }
  cout << m - int(s.size()) <<endl;
}
  