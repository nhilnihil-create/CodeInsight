#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  string w;
  cin >> w;
  vector<int> alpha(26,0);
  rep(i,w.size()){
    alpha[w[i]-'a']++;
  }
  rep(i,alpha.size()){
    if(alpha[i]%2==1){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}