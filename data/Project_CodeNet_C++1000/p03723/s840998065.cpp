#include <bits/stdc++.h>
using namespace std;
int main(){
  long long A, B, C;
  cin >> A >> B >> C;
  if (A == B && B == C && A % 2 == 0){
    cout << -1 << endl;
  } else {
    int cnt = 0;
    while (1){
      if (A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
        long long A2 = (B + C) / 2;
        long long B2 = (C + A) / 2;
        long long C2 = (A + B) / 2;
        A = A2;
        B = B2;
        C = C2;
        cnt++;
      } else {
        break;
      }
    }
    cout << cnt << endl;
  }
}