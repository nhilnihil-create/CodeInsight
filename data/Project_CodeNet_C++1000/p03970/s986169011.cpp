#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  string s;
  cin>>s;
  int cnt(0);
  string t = "CODEFESTIVAL2016";
  for(int i(0);i<16;i++){
    if(s[i] != t[i]) cnt++;
  }
  cout << cnt << endl;
  return 0;
}

