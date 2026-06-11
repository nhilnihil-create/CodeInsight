#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;
const int MOD = 1000000007;

signed main() {
  int N;
  cin >> N;
  
  vector<int> T(N);
  vector<int> A(N);
  for( int i = 0; i < N; i++ ) cin >> T.at(i) >> A.at(i);
  
  int nowT = T.at(0);
  int nowA = A.at(0);
  
  for( int i = 1; i < N; i++ ){
    int nT = nowT/T.at(i);
    int nA = nowA/A.at(i);
    if( nowT%T.at(i) != 0 ) nT++;
    if( nowA%A.at(i) != 0 ) nA++;
    int n = max(nT, nA);
    nowT = n*T.at(i);
    nowA = n*A.at(i);
  }
  
  cout << nowT+nowA << endl;

    
  
  
}
