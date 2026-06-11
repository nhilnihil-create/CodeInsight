#include<bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int nowA = A, nowB = B, nowC = C;
  int time = 0;

  if((A == B) && (B == C)){
    if((A % 2 != 0) || (B % 2 != 0) || (C % 2 != 0)){
      goto Next;
    }
    time = -1;
  }

  else{
    while((nowA % 2 == 0) && (nowB % 2 == 0) && (nowC % 2 == 0)){
      time++;
      nowA = (B / 2) + (C / 2);
      nowB = (A / 2) + (C / 2);
      nowC = (A / 2) + (B / 2);
      A = nowA, B = nowB, C = nowC;
    }
  }
  Next:
  cout << time << endl;
}