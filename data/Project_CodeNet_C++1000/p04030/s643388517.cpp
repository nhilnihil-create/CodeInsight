#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
 
int main() {
string s;
cin >> s;
stack<char> t;
rep(i,s.size()){
  if(s.at(i) == '0'){
   t.push('0');
  }
  else if(s.at(i) == '1'){
    t.push('1');
  }
  else if(s.at(i) == 'B'){
    if(!t.empty()) t.pop();
  }
}
  int n = t.size();
  vector<char> b;
 rep(i,n){
   b.push_back(t.top());
   t.pop();
 }
  reverse(b.begin(),b.end());
  rep(i,n) cout << b.at(i);
}