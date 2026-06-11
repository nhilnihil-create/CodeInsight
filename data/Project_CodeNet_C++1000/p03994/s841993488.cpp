#include<bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  string s; cin >> s;
  lint K; cin >> K;
  lint counter = 0;
  for(lint i = 0; i < s.size(); i++){
    if(s[i] == 'a') continue;
    lint need = lint('z' - s[i]) + 1;
    if(counter + need <= K){
      s[i] = 'a'; counter += need;
    }
  }
  s[s.size() - 1] = char(s[s.size() - 1] + ((K - counter) % 26));
  cout << s << endl;
}