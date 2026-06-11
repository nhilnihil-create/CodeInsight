#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t x,ans;
  cin >> x;
  ans = ((x-1)/11+1)*2 -  ((x%11>=1)&&(x%11<=6))*1;
  cout << ans << endl;
  return 0;
}