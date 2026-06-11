#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint ans;

signed main(){
  string s; cin >> s;
  lint K; cin >> K;
  lint counter = 0;
  lint start = 0;
  for(lint start = 0; start < s.size(); start++){
    if(s[start] == 'a') continue;
    lint need = 'z' - s[start] + 1;
    if(K - counter >= need){
      s[start] = 'a';
      counter += need;
    }
  }
  s[s.size() - 1] += (K - counter) % 26;
  cout << s << endl;
}
