#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  const string alp="qwertyuiopasdfghjklzxcvbnm";
  map<char,int>al;
  for(int i=0;i<26;i++)
    al[alp.at(i)]=0;
  for(int i=0;i<s.size();i++)
    al[s.at(i)]++;
  string ans="None";
  for(pair<char,int> x:al){
    if(x.second==0){
      ans=x.first;
      break;
    }
  }
  cout << ans << endl;
}