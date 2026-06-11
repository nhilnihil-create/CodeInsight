#include<bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  int ans;
  cin >> A >> B;
  if(A + B < 24){
    ans = A + B;
  }else{
    ans = A + B - 24;
  }
  cout << ans << "\n";
  return 0;
}
