#include<bits/stdc++.h>
using namespace std;

int main(){
  string s; cin >> s;
  map<int, int>mp;
  int n = s.size();
  for(int i = 0; i < n; ++i){
    mp[s[i]-'a']++;
    if(mp[s[i]-'a'] > 1) {
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0; 
}
