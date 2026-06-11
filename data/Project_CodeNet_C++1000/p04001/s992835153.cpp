#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

long long sum(int i, string &s){
  int n = s.size()-1;
  vector<long long> part;
  part.push_back(s[0]-'0');
  
  for(int j=0; j<n; j++){
    if((i>>j)&1){
      part.push_back(s[j+1]-'0');
    }
    else{
      part.back() *= 10;
      part.back() += s[j+1]-'0';
    }
  }
  
  long long rtn = 0;
  for(int j=0; j<part.size(); j++){
    rtn += part[j];
  }
  //cout << rtn << endl;
  return rtn;
}

int main(){
  string s; cin >> s;
  int n = s.size()-1;
  long long ans = 0;
  
  rep(i, 1<<n){
    ans += sum(i, s);
  }
  cout << ans << endl;
  return 0;
}