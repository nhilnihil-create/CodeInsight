#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;

  if(s.size()==2 && s[0] == s[1]){
    cout << s.size() << endl;
    return 0;
  }
  
  //rep(i,s.size()){
  while(true){
    auto end = s.end()-1;
    s.erase(end);
    int n = s.size();
    string left = "";
    string right = "";
    
    if(s.size()%2!=0) continue;
    
    /*left = s.substr(0,s.size()/2);
      right = s.substr(s.size()/2,s.size());*/
    
    rep(j,s.size()/2) left+=s[j];
    //for(int j = s.size()/2;j<s.size();j++) right+=s[j];
    for(int j = n/2;j<n;j++) right+=s[j];
    
    if(left==right && s.size()%2==0){
      cout << s.size() << endl;
      return 0;
    }
  }
  
  return 0;
}
