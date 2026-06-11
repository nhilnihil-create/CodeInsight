#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  string s; cin >> s;
  vector<char> all;
  
  char c = 'a';
  rep(i,26){    
    all.push_back(c);
    c++;
  }

  rep(i,all.size()){
    bool n_in = false;
    rep(j,s.size())
      if(all[i]==s[j]) n_in = true;
    if(!n_in){
      cout << all[i] << endl;
      return 0;
    }
  }

  cout << "None" << endl;
  
  return 0;
}
