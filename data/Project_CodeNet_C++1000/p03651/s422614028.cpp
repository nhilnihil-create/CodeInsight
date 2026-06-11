#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  int GCD = A[0];
  for(int i = 1; i < N; i++){  
    GCD = __gcd(GCD, A[i]);
  }
  for(int i = 0; i < N; i++){  
    int dif = A[i] - K;
    if(dif == 0 || (dif > 0 && dif % GCD == 0)){  
      cout << "POSSIBLE" <<endl; 
      return 0;
    }
  }
  cout << "IMPOSSIBLE" <<endl;
}
