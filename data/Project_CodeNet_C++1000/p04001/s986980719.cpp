#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  long long ans;
  ans=0;
  cin >> s;
  for (int i=0 ; i<(1<<(s.size()-1)); i++){
    bitset<10> p(i);
    string t="";
    for (int j=0; j<s.size(); j++){
      t+=s.at(j);
      if(p[j]==1){
        ans += stoll(t);
        t="";
      }
    }
    if(t.size()>0){
      ans += stoll(t);
    }
  }
  cout << ans << endl;
}

