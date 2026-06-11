#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n=s.size();
  if(s[0]==s[s.size()-1]){
    n-=3;
  }
  else{
    n-=2;
  }

  if(n%2==0){
    cout<<"Second"<<endl;
  }
  else{
    cout<<"First"<<endl;
  }

  return(0);
}
