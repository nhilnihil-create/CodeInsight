#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n, p; cin >> n >> p;
  vector<int> v(n);
  bool flag = true;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    if(v[i] % 2) flag = false;
  }
  if(flag){
    if(p == 0){
      long long ans = pow(2, n);
      cout << ans << endl;
    }
    else cout << 0 << endl;
  }
  else{
    long long ans = pow(2, n - 1);
    cout << ans << endl;  
  }
}