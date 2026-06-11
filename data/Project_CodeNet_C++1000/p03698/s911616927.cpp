#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  int a=0;
  for(int i=0;i<s.size();i++){
    for(int j=i+1;j<s.size();j++){
      if(s[i]==s[j]){
        a++;
      }
    }
  }
  if(a==0){
    cout << "yes" << endl;
  }
  else{
    cout<<"no"<<endl;
  }
}