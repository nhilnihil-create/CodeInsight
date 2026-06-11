#include <bits/stdc++.h>
using namespace std;

int main(){
  string s; cin>>s;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]==s[i+1]){
      cout<<i+1<<' '<<i+2<<endl;
      return 0;
    }else if(s[i]==s[i+2] && i+2!=s.size()){
      cout<<i+1<<' '<<i+3<<endl;
      return 0;
    }
  }
  cout<<-1<<' '<<-1<<endl;
}