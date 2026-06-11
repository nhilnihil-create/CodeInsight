#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int n;
  cin >> n;
  string s1,s2;
  cin >> s1 >> s2;
  bool seq = false;
  vector<int> data;
  rep(i,n-1){
    if(s1.at(i) == s1.at(i+1)) seq = true;
    else{
      if(seq){
        seq = false;
        data.push_back(2);
      }else{
        data.push_back(1);
      }
    }
  }
  if(seq) data.push_back(2);
  else data.push_back(1);
  long ans = 1;
  rep(i,data.size()){
    if(i == 0){
      if(data.at(i) == 1) ans *= 3;
      else ans *= 6;
      continue;
    }
    if(data.at(i-1) == 1 && data.at(i) == 1) ans = (ans*2)%MOD;
    else if(data.at(i-1) == 1 && data.at(i) == 2) ans = (ans*2)%MOD;
    else if(data.at(i-1) == 2 && data.at(i) == 2) ans = (ans*3)%MOD;
  }
  cout << ans << endl;
}
