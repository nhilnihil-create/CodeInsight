#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string w; cin >> w;
  map<char,int> mp;

  rep(i,w.size()) mp[w[i]]++;

  bool even = true;
  for(auto x : mp){    
    if(x.second % 2 != 0) even = false;
  }
  
  if(even) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
