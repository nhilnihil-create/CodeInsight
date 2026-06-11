#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
using namespace std;

int main() {
  string s, t;
  int q, a, b, c, d;
  cin >> s >> t >> q;
  vector<int> scnt(s.size()), tcnt(t.size());
  if(s[0] == 'A')scnt.at(0) = 1;
  else scnt.at(0) = 2;
  if(t[0] == 'A')tcnt.at(0) = 1;
  else tcnt.at(0) = 2;
  for(int i = 1; i < s.size(); i++) {
    int now;
    if(s[i] == 'A')now = 1;
    else now = 2;
    scnt.at(i) = scnt.at(i-1) + now;
  }
  for(int i = 1; i < t.size(); i++) {
    int now;
    if(t[i] == 'A')now = 1;
    else now = 2;
    tcnt.at(i) = tcnt.at(i-1) + now;
  }
  rep(i, q) {
    cin >> a >> b >> c >> d;
    if((scnt[b-1] - scnt[a-2]) % 3 == (tcnt[d-1] - tcnt[c-2]) % 3)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;
  }
}