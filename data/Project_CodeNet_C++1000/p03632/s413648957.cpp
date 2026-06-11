#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  
  int t = min(B,D) - max(A,C);
  if(t < 0){
    t = 0;
  }
  cout << t << endl;
}