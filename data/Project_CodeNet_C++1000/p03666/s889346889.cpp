#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  bool ans = false;
  for (int i = 0; i <= N - 1; i++){
    long long ub = D * i - C * (N - 1 - i);
    long long lb = C * i - D * (N - 1 - i);
    if (A + lb <= B && B <= A + ub){
      ans = true;
    }
  }
  if (ans){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}