#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  string s;
  cin>>s;
  s.erase(s.size()-1);
  while(s.size()>0){
    if(s.size()%2==0){
      if(s.substr(0,s.size()/2)==s.substr(s.size()/2,s.size()/2)){
        cout<<s.size()<<endl;
        return 0;
      }
    }
    s.erase(s.size()-1);
  }
}