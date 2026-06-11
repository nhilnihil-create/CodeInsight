#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string s;cin>>s;
  string t=s;
  for(int i=0;i<s.size();i++){
    if(t[i]=='b')t[i]='d';
    else if(t[i]=='d')t[i]='b';
    else if(t[i]=='p')t[i]='q';
    else if(t[i]=='q')t[i]='p';
    if(t[i]!=s[s.size()-1-i]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}