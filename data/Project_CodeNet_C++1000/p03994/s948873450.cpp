#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  for(ll i=0;i<s.size();i++) {
    if('z'-s[i]<k&&s[i]!='a') {
      k-='z'-s[i]+1;
      s[i]='a';
    }
  }
  k%=26;
  if(k>0) {
    s[s.size()-1]=char(s[s.size()-1]+k);
    k=0;
  }
  cout << s << endl;
}