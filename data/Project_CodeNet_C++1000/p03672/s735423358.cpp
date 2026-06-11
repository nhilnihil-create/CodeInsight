#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin>>s;
  for(int i=s.length()-2; i>0; i-=2){
    s.pop_back(); s.pop_back();
    int half=s.length()/2;
    if(s.substr(0,half)==s.substr(half,half)){
      cout<<s.length();
      return 0;
    }
  }
}