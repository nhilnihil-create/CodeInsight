#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;cin>>S;
  int n[]={0,0,0,0};
  map<char,int> mp{{'N',0},{'S',1},{'E',2},{'W',3}};
  for(auto c:S) n[mp[c]]=1;
  if(n[0]^n[1] || n[2]^n[3]) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
