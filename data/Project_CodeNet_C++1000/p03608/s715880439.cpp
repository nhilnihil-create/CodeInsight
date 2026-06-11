#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N,M,R;
  cin >> N >> M >> R;

  vector<int> r(R);
  for(int i = 0; i < R; i++){
    cin >> r[i];
    r[i]--;
  }
  sort(r.begin(), r.end());


  vector<vector<int>> v(N);
  vector<vector<ll>> len(N, vector<ll>(N, MAX));

  for(int i = 0; i < M; i++){
    int tmp1, tmp2;
    ll C;
    cin >> tmp1 >> tmp2 >> C;
    tmp1--; tmp2--;
    v.at(tmp1).push_back(tmp2);
    v.at(tmp2).push_back(tmp1);
    len[tmp1][tmp2] = C;
    len[tmp2][tmp1] = C;
  }
  // ワーシャルフロイド

  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
        len[j][i] = min(len[j][i], len[k][i] + len[j][k]);
      }
    }
  }

  auto dist = [&len](int x, int y){
    if(x > y){
      return len[y][x];
    }
    return len[x][y];
  };

  ll ans = MAX;
  do{
    ll tmp = 0;
    for(int i = 1; i < r.size(); i++){
      tmp += dist(r[i-1], r[i]);
    }
    ans = min(ans, tmp);

  } while(next_permutation(r.begin(), r.end()));

  cout << ans << endl;

}
