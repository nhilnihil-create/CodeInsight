#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >>w;
  vector<char>S(w.size());
  for(int i=0; i<w.size(); i++){
    S.at(i)=w.at(i);
  }
  sort(S.begin(), S.end());
  
  string ans="Yes";
  for(int i=1; i<w.size()/2; i+=2){
    if(S.at(i)!=S.at(i-1))ans="No";
  }
  if(w.size()%2==1)ans ="No";
  
  cout << ans <<endl;
  
}