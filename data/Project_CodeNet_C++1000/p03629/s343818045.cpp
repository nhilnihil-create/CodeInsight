#include<bits/stdc++.h>
#define mx 5005
#define inf 100000000000005
using namespace std;

int t, i;
bitset<26> bt[26][10000], m;
string s, ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  for(i = s.size()-1; i >= 0; i--){
    bt[s[i] - 'a'][t] = m;
    m.set((int)(s[i] - 'a'));
    if(m.all()){
      t++;
      m.reset();
    }
  }
  while(t+1){
    for(i = 0; m[i]; i++);
    ans.push_back((char)('a' + i));
    if(t--) m = bt[i][t];
  }
  cout << ans << '\n';
}
