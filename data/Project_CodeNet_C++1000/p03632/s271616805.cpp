#include<bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int time = 0;
  if(B < C || D < A) {
    time =0;
  }else{
    time = min(B, D) - max(A, C);
  }
  
  cout << time << endl;
}