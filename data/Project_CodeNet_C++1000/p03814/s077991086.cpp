#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  string s;
  int index1, index2, i;
  cin >> s;
  
  for(i=0; i<s.size();i++){
    if(s[i]=='A'){
      index1=i;
      break;
    }
  }
    
  for(i=s.size()-1; i>-1;i--){
    if(s[i]=='Z'){
      index2=i;
      break;
    }
  }
  
  cout << index2-index1+1;
}



