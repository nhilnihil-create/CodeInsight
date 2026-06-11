#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;

signed main() {
  int N;
  cin >> N;
  
  vector<int> A(N);
  map<int, int> num;
  for( int i = 0; i < N; i++ ){
    cin >> A.at(i);
    if( num.count(A.at(i)) ) num.at(A.at(i))++;
    else num[A.at(i)] = 1;
  }
  
  int start;
  if( N%2 == 0 ) start = 1;
  else start = 0;
  for( auto p : num ){
    if( p.first == start ){
      if( start == 0 && p.second != 1 ){
        cout << 0 << endl;
        return 0;
      }else if( start != 0 && p.second != 2 ){
        cout << 0 << endl;
        return 0;
      }
      start += 2;
    }else{
      cout << 0 << endl;
      return 0;
    }
  }
  
  int ans = 1;
  for( int i = 0; i < N/2; i++ ){
    ans = (ans*2)%MOD;
  }
  cout << ans << endl;
  
  
  
}
