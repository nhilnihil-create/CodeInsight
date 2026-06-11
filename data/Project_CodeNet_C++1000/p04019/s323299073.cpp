#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  cin>>s;
  map<char,int> mp;
  mp['N']=0;mp['W']=0;mp['E']=0;mp['S']=0;
  rep(i,s.size()){
    mp[s[i]]++;
  }
  bool ans =false;
  if(mp['N']!=0&&mp['W']!=0&&mp['E']!=0&&mp['S']!=0){
    ans=true;
  }
  if(mp['N']==0&&mp['W']!=0&&mp['E']!=0&&mp['S']==0){
    ans=true;
  }
  if(mp['N']!=0&&mp['W']==0&&mp['E']==0&&mp['S']!=0){
    ans=true;
  }
  if(ans){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}