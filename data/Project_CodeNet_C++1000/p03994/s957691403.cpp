#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;cin>>s;
  int k;cin>>k;
  rep(i,s.size()-1) {
    char c = s[i];
    int x = 'z' - c + 1;
    if (x==26 || x > k) cout<<c;
    else {
      cout<<'a';
      k -= x;
    }
  }
  char c = s[s.size()-1];
  c = (c - 'a' + k) % 26 + 'a';
  cout<<c<<endl;
}
