#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)

ll mod = 1e9 + 7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;
  ll s[4500];
  ll mm;
  REP(i, 4500){
    s[i] = i * (i + 1) / 2;
    if(s[i] >= n){
      mm = i;
      break;
    }
  }

  ll rec = s[mm] - n;
  if(rec == 0){
    REP(i, mm) cout << i + 1 << endl;
  }
  else{
    REP(i, mm){
      if(i + 1 == rec) continue;
      else cout << i + 1 << endl;
    }
  }
  return 0;
}
