#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S1,S2;
  cin >>N>> S1 >>S2;
  int row = 0 ;
  long ans =1;

  if(S1[0] == S2[0]) {
    ans *=3;
    row += 1;
  }
  else{
    ans *= 6;
    row +=2;
  }

  while(row<N){
    if(S1[row] == S2[row]) {
      if(S1[row-1]==S2[row-1]){
        ans *= 2;
        row +=1;
      }
      else{
        ans =ans;
        row +=1;
      }
    }
    else{
      if(S1[row-1]==S2[row-1]){
        ans *= 2;
        row +=2;
      }
      else{
        ans *=3;
        row +=2;
      }
    }
  //  cout << ans <<endl;
  }

  ans %= 1000000007;

  cout << ans <<endl;

}
