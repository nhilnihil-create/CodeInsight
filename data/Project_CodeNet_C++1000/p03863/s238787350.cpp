#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
  cin>>s;
  int N=s.size();
  if(N%2==0){
  if(s.at(0)==s.at(N-1)){
     cout<<"First"<<endl;
  }else{
  cout<<"Second"<<endl;
  }
  }else{
  if(s.at(0)==s.at(N-1)){
    cout<<"Second"<<endl;
  }else
    cout<<"First"<<endl;
  }
    return 0;
}