#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  string S;
  cin >> S;
  map<char, ll> mp;
  rep(i,S.size()){
    mp[S[i]]++;
  }
  bool a = true;
  for (auto p : mp){
    if(p.second % 2 != 0){
      a = false;
    }
  }
  if(a){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}