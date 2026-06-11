#include <bits/stdc++.h>
typedef long long LL;
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;
int main(void)
{
  LL n, m;
  cin >> n >> m;
  vector<vector<LL>> a(n+1);
  vector<bool> b(n+1, false);
  vector<LL> s(1),t(1);
  cin >> s[0] >> t[0];
  b[s[0]]=true;
  b[t[0]]=true;
  REP(i,m-1) {
    LL l, r;
    cin >> l >> r;
    a[l].push_back(r);
    a[r].push_back(l);
  }
  for(;;) {
    LL l=s.back();
    for(LL x:a[l]) {
      if(b[x]) continue;
      b[x] = true;
      s.push_back(x);
      break;
    }
    if(l==s.back()) break;
  }
  for(;;) {
    LL r=t.back();
    for(LL x:a[r]) {
      if(b[x]) continue;
      b[x] = true;
      t.push_back(x);
      break;
    }
    if(r==t.back()) break;
  }
  reverse(s.begin(),s.end());
  for(auto x:t) s.push_back(x);

  cout << s.size() << endl;
  REP(i, s.size()) {
    if(i) cout << " ";
    cout << s[i];
  }
  cout << endl;
  return 0;
}
