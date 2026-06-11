#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;cin>>s;
  int ans=0;
  int size=s.size();
  char tmp=s.at(0);
  for(int i=1;i<size;i++){
    if(s.at(i)!=tmp){
      ans++;
      tmp=s.at(i);
    }
  }
  cout <<ans<<endl;
}