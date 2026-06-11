#include<bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;
  int n=s.size();
  map<char,int> mp;
  for(int i=0;i<n;++i){
    mp[s[i]];
  }
  if(n==mp.size()) cout << "yes" <<endl;
  else cout << "no" << endl;

  return 0;
}
