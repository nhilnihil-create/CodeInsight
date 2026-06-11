#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin>>s;
  sort(s.begin(),s.end());
  for(char c='a'; c<'a'+26; c++){
    if(s.find(c)==-1){
      cout<<c;
      return 0;
    }
  }
  cout<<"None";
}