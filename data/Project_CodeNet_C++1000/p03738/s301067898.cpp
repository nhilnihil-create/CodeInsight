#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  string ans="EQUAL";
  
  if(A.size()>B.size())ans="GREATER";
  else if(A.size()<B.size())ans="LESS";
  else{
    for(int i=0; i<A.size(); i++){
      if(A.at(i)>B.at(i)){
        ans ="GREATER";
        break;
      }
      else if(A.at(i)<B.at(i)){
        ans ="LESS";
        break;
      }
    }
  }
  
  cout << ans << endl;
}
