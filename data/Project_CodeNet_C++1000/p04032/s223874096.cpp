#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  for(int i=1;i<s.size();i++){
    if(s.at(i-1)==s.at(i)){
      cout<<i<<' '<<i+1<<endl;
      return 0;
    }
    if(i-2>=0&&s.at(i-2)==s.at(i)){
      cout<<i-1<<' '<<i+1<<endl;
      return 0;
    }
  }
  cout<<-1<<' '<<-1<<endl;
}