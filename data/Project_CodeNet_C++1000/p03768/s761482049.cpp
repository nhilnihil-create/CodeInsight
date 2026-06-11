#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

int n, m;
int q;
vector<int> edge[108000];
int query[11][108000];
int a, b, v, d;
int c[108000];

int main(){
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  cin >> q;
  for(int i = 1;i <= q;i++){
    cin >> v >> d >> c[i];
    query[d][v] = i;
  }
  for(int d = 10;d >= 1;d--){
    for(int i = 1;i <= n;i++){
      query[d-1][i] = max(query[d-1][i], query[d][i]);
      for(auto to:edge[i]){
	query[d-1][to] = max(query[d-1][to],query[d][i]);
      }
    }
  }
  for(int i = 1;i <= n;i++){
    cout << c[query[0][i]] << endl;
  }
  return 0;
}