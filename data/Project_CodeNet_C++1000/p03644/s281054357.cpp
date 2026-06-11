#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  
  if(N>=64)ans=64;
  else if(N>=32)ans=32;
  else if(N>=16)ans=16;
  else if(N>=8)ans=8;
  else if(N>=4)ans=4;
  else if(N>=2)ans =2;
  else ans=1;
  
  cout << ans << endl;
}