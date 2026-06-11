#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  vector<string> s(3);
  rep(i,3) cin >>s[i];
  int ans = 0;
  while(true){
    string t = s[ans];
    if(t.empty()){
      cout << char(ans+'A') << endl;
      return 0;
    }
    s[ans] = t.substr(1,t.size()-1);
    ans = t[0]-'a';
  }
  return 0;
}