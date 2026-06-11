#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 10000000000000;
vector<vector<int>> cost(200, vector<int>(200,INF));
void warshall_floyd( int N ){
  for( int i = 0; i < N; i++ ){ //経由
    for( int j = 0; j < N; j++ ){ //始点
      for( int k = 0; k < N; k++ ){ //終点
        cost.at(j).at(k) = min(cost.at(j).at(k), cost.at(j).at(i)+cost.at(i).at(k));
      }
    }
  }
}

signed main(){
  int N, M, R;
  cin >> N >> M >> R;
  
  vector<int> r(R);
  for( int i = 0; i < R; i++ ){
    cin >> r.at(i);
    r.at(i)--;
  }
  sort( r.begin(), r.end() );
  
  for( int i = 0; i < M; i++ ){
    int A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    cost.at(A).at(B) = C;
    cost.at(B).at(A) = C;
  }
  
  for( int i = 0; i < N; i++ ) cost.at(i).at(i) = 0;
  warshall_floyd(N);
  
  int ans = INF;
  do{
    int now = 0;
    for( int i = 0; i < R-1; i++ ){
      now += cost.at(r.at(i)).at(r.at(i+1));
    }
    ans = min(ans, now);
  }while( next_permutation(r.begin(), r.end()) );
  
  cout << ans << endl;
  
}
