#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();

  map<char,int> mp;

  int cnt = 26;
  for(char al = 'a'; al <= 'z'; al++){
    mp[al] = cnt;
    --cnt;
  }
  mp['a'] = 0;


  //for( auto x : mp) cout << x.second << endl;


  REP(i,n){
    if(mp[s[i]] > k) continue;
    k -= mp[s[i]];
    s[i] = 'a';
    //cout << k << endl;
    if(k <= 0) break;
  }

  if(k > 0) {
    k %= 26;
    s[n-1] += k;
  }


  cout << s << endl;

  return 0;
}
