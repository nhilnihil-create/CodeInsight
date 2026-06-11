#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]==','){
      cout<<" "<<flush;
    }else{
      cout<<s[i]<<flush;
    }
  }
  cout<<endl;
}