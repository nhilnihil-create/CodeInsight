#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<ll> s(n);
  
  for(int i=0; i<n; i++) cin >> s[i];
  sort(s.begin(), s.end());
  ll sum = accumulate(s.begin(), s.end(), 0);
  
  if(sum%10==0){
    for(int i=0; i<n; i++){
      if(s[i]%10){
        sum -= s[i];
        break;
      }
    }
  }
  
  if(sum%10==0) sum=0;
  
  cout << sum << endl;
  

  return 0;
}