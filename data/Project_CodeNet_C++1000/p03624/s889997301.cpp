#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >>s;
  map<char,int> mp;
  for(char a='a';a<='z';++a){
    mp[a]++;
  }
  int n=s.size();
  for(int i=0;i<n;++i){
    mp[s[i]]++;
  }
  bool ok=false;
  char ans;
  for(auto p : mp){
    if(p.second==1){
      ok=true;
      ans=p.first;
      break;
    }
  }
  if(ok) cout << ans << endl;
  else cout << "None" << endl;

  return 0;
}
