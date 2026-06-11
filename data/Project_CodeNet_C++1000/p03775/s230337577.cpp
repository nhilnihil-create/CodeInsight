#include <bits/stdc++.h>
using namespace std;

int main(){
  double n;
  cin >> n;
  int64_t ans=10,s=0;
  for(int i=1;i<=sqrt(n);i++){
    if(n/i==ceil(n/i)){
      s=max(log10(i),log10(n/i))+1;
      ans=min(ans,s);
    }
  }
  cout << ans << endl;
  return 0;
}