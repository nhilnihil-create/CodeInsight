#include <bits/stdc++.h>
using namespace std;


int main() {
  string s;
  cin>>s;
  int n=s.size();
  for(int i=0;i<n-1;i++){
    string  t=s.substr(i,2);
    if(t[0]==t[1]){
      cout<<i+1<<" "<<i+2<<endl;
      return 0;
    }
  }

  for(int i=0;i<n-2;i++){
    string  t=s.substr(i,3);
    if(t[0]==t[1]||t[1]==t[2]||t[2]==t[0]){
      cout<<i+1<<" "<<i+3<<endl;
      return 0;
    }
  }

cout<<-1<<" "<<-1<<endl;

}
