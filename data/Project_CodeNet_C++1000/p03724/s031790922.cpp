#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e15;
using Graph = vector<vector<int>>;

signed main(){
  int N, M;
  cin >> N >> M;
  vector<int> num(N+1);
  for( int i = 0; i < M; i++ ){
    int A, B;
    cin >> A >> B;
    num[A]++;
    num[B]++;
  }

  for( int i = 1; i <= N; i++ ){
    if( num[i]%2 == 1 ){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
