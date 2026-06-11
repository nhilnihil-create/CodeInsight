#include<bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  map<char,int> mp;
  for(int i=0; i<S.size(); i++){
    if(mp.count(S.at(i))){
      mp[S.at(i)]++;
    }
    else{
      mp[S.at(i)] = 1;
    }
  }
  int64_t ans = S.size() * (S.size()-1) / 2;
  ans++;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    int64_t x = itr->second;
    ans -= x * (x-1) / 2;
  }
  cout << ans << endl;
}