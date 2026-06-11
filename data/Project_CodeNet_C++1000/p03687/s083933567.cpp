#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}



int main(void)
{
  string s;
  cin >> s;
  char c;
  ll min_cnt = 1000;
  for(c = 'a'; c <= 'z'; c++) {
    bool ok = false;
    REP(i, s.size()) {
      if(s[i] == c) ok = true;
    }
    if(!ok) continue;
    ll cnt = 0;
    string s1 = s;
    while(1) {
      bool ok = true;
      REP(i, s1.size()) {
	if(s1[i] != c) ok = false;
      }
      if(ok) break;
      REP(i, s1.size()-1) {
	if(s1[i+1] == c) s1[i] = c;
      }
      s1.erase(s1.size()-1);
      cnt ++;
    }
    //    cout << s1 << " " << cnt << endl;
    if(min_cnt > cnt) min_cnt = cnt;
  }

  cout << min_cnt << endl;

}
