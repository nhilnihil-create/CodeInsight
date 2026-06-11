#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,ans = 13;
  cin >> n;
  for (int i=1;i<=sqrt(n);i++){
    if (n % i == 0){
      ans = min(ans,(long long)to_string(n/i).size());
    }
  }
  cout << ans << endl;
}