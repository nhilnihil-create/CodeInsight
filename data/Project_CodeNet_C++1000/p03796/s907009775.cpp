#include<bits/stdc++.h>
using namespace std;
const int d=1e9+7;
int main(){
  int n;
  int64_t ans=1;
  cin >> n;
  for(int i=1;i<=n;i++){
    ans=(i*ans)%d;
  }
  cout << ans << endl;
}