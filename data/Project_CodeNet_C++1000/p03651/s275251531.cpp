#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int g = 0;
  int mx = 0;
  for (int i = 0; i < N; i++){
    g = __gcd(g, A[i]);
    mx = max(mx, A[i]);
  }
  if (K > mx || K % g != 0){
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << "POSSIBLE" << endl;
  }
}