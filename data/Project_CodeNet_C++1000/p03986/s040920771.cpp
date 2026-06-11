#include <bits/stdc++.h>
using namespace std;

int main(){
  string X;
  cin >> X;
  int64_t ans=0;
  int64_t n=0;
  for(int i=0;i<X.size();i++){
    if(X.at(i)=='S'){
      n++;
    }else{
      if(n>0){
        ans++;
        n--;
      }
    }
  }
  ans=X.size()-2*ans;
  cout << ans << endl;
  return 0;
}
