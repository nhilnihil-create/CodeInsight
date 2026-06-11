#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n; cin >>n;
  int sum = 0;
  vector<int> s(n);
  rep(i,n){
    cin >>s[i];
    sum += s[i];
  }
  if(sum%10!=0){
    cout << sum << endl;
    return 0;
  }
  sort(s.begin(), s.end());
  rep(i,n){
    if((sum-s[i])%10!=0){
      cout << sum - s[i] << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0; 
}
