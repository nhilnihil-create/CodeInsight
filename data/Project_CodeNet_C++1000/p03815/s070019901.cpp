#include<bits/stdc++.h>
using namespace std;
int main(){
  long N;
  cin >> N;
  
  long ans = 0;
  
  ans += N / 11;
  ans = ans * 2;
  int tmp = N % 11;
  if(tmp==0){
    //
  } else if(tmp > 6){
    ans += 2;
  } else {
    ans += 1;
  }
  cout << ans << endl;

} 