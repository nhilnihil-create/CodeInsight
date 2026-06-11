#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int N, M, R;
int inf = 1000000000;
int d[200][200];

void warshall_floyd(){
  rep(k, N)rep(i, N)rep(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main(){
  cin >> N >> M >> R;
  int r[R];
  rep(i, R){
    cin >> r[i];
    r[i] --;
  }
  sort(r, r+R);
  rep(i, N)rep(j, N) d[i][j] = inf;
  rep(i, N) d[i][i] = 0;
  
  rep(i, M){
    int a, b, c;
    cin >> a >> b >> c;
    d[a-1][b-1] = c;
    d[b-1][a-1] = c;
  }
  
  warshall_floyd();
  int ans = inf;
  do{
    int ans_temp = 0;
    rep(i, R-1){
      ans_temp += d[r[i]][r[i+1]];
    }
    ans = min(ans, ans_temp);
  }while(next_permutation(r , r+R));
  cout << ans << endl;
}