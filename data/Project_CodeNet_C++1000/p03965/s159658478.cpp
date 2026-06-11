#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s;
  int gc = 0,pc = 0,ans = 0;
  cin >> s;
  rep(i,0,s.size()){
    if(s[i] == 'g'){
      if(pc < gc){pc++;ans++;}
      else gc++;
    }
    else{
      if(pc < gc) pc++;
      else{gc++;ans--;}
    }
  }
  cout << ans << endl;
}