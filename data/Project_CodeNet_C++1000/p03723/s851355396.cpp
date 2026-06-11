#include <iostream>

using namespace std;

int main(){
  long long A, B, C;
  int ans=0;
  cin >> A >> B >> C;

  if (A == B && B == C && C == A && A%2==0) {
    printf("-1\n");
  }else{
    while (A%2==0 && B%2==0 && C%2==0){
      long long Ah = A/2, Bh = B/2, Ch = C/2;
      A = Bh + Ch;
      B = Ah + Ch;
      C = Ah + Bh;
      ans++;
    }
    printf("%d\n", ans);
  }
}
