#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n;
  cin >> n;
  vector<int> v(0);
  string s;
  cin >> s;
  rep(i,n-1){
    if(s[i+1] == s[i]){
      v.push_back(1);
      if(i != n-2){
        i++;
      }
    }
    else{
      v.push_back(2);
    }
  }
  if(s[n-2] != s[n-1]){
    v.push_back(2);
  }
  ll ans = 0;
  ll m = v.size();
  
  if(m == 1){
    if(v[0] == 2){
      cout << 3;
    }
    else{
      cout << 6;
    }
  }
  else{
    if(v[0] == 2){
        ans = 3;
      }
      else{
        ans = 6;
      }
    
    rep(i,m-1){
    
    
      if(v[i] == 2 && v[i+1] == 2){
        ans = (ans * 2) % 1000000007;
      }
      else if(v[i] == 2 && v[i+1] == 1){
        ans = (ans * 2) % 1000000007;
      }
      else if(v[i] == 1 && v[i+1] == 1){
        ans = (ans * 3) % 1000000007;
      }
     
      }
    cout << ans << endl;
  }
  
 
   
  return 0;
}


