#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  string s; cin >> s;
  int ans = 0;
  rep(i, s.size()){
    if(i % 2 == 0){
      if(s[i] == 'p') ans--;
    }
    else{
      if(s[i] == 'g') ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
