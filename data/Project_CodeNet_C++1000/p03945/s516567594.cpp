#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Graph = vector<vector<ll>>;

int main(){
  int ans = 0;
  string s;cin>>s;
  for (int i = 1; i < s.size(); i++) {
    if(s.at(i) != s.at(i-1))ans++;
  }
  cout << ans<< endl;
}