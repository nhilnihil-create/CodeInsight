#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int time = min(B, D) - max(A, C);
  
  cout << (time > 0 ? time : 0) << endl;
}