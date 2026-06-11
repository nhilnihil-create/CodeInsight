#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  set<int> Set;
  for(int i=0; i<s.size(); i++){
    Set.insert(s[i]);  
  }
  if(s.size()==Set.size()){
    cout<<"yes"<<endl;  
  } else {
    cout<<"no"<<endl;      
  }
  return 0;
}
