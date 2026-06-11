#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  for(int i=0; i<n; ++i){
    if(s[i] == 'a') continue;
    if('z'+1 -s[i] <= k){
      k -= 'z'+1 -s[i];
      s[i] = 'a';
    }
  }
  s[n-1] += k%26;
  if(s[n-1] > 'z') s[n-1] -= 26;
  cout << s << endl;
}