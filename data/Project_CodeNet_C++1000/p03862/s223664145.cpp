#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long int n, x;
  cin >> n >> x;
  long long int a, prev;
  cin >> prev;
  long long int ans=0;
  for(int i=1; i<n; i++){
    cin >> a;
    if(a+prev>x){
      ans += a+prev-x;
      if(x-prev<0) prev = 0;
      else prev = x-prev;
    }else{
      prev = a;
    }
  }
  cout << ans << endl;
  return 0;
}
