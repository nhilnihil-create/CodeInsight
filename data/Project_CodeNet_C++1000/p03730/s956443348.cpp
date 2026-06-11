#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int a = A % B;
  for (int i = 2; i < 1000000; i++){
    int b = (A * i) % B;
    if (b == C){
      cout << "YES" << endl;
      return 0;
    }
    if (b == a){
      cout << "NO" << endl;
      return 0;
    }
  }
  
  cout << "NO" << endl;
      return 0;
}
