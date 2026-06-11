#include <bits/stdc++.h>
using namespace std;

int main(){
  long long x;
  cin >> x;
  long long ans;
  if(x%11==0) ans=x/11*2;
  else if(x%11<=6) ans=x/11*2+1;
  else ans=x/11*2+2;
  cout << ans << endl;
}