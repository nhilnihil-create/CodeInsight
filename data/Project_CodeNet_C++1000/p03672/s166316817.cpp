#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define ll long long

int main() {
  string s;
  cin>>s;
  vector<char> v(s.size());
  for(int i=0;i<s.size();i++) v[i]=s[i];
  
  
  while(1){
    
    v.pop_back();
    
    if(v.size()%2==0){
      int cnt=0;
      for(int j=0;j<v.size()/2;j++) if(v[j]==v[j+v.size()/2]) cnt++;
      if(cnt==v.size()/2){
        cout<<v.size()<<endl;
        break;
      }
    }
  }
}