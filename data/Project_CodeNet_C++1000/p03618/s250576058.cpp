# include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int freq[26];
  memset(freq, 0, sizeof(freq));
  for(char ch : s) freq[ch-'a']++;

  long long ans = 1ll * s.size() * (s.size()-1) / 2;
  for(int i=0; i<26; i++){
    ans -= 1ll * freq[i] * (freq[i]-1) / 2;
  }
  ans++;

  cout << ans << endl;
  return 0;
}