#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define p_ll pair<ll, ll>
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  string A; cin >> A;
  int l = A.length();
  int a[26] = {};
  vector<int> pos = {l};
  for (int i=l-1; i>=0; i--) {
    a[A[i]-'a']++;
    bool ok = true; 
    rep(num,26) if (a[num]==0) ok = false;
    if (ok) { pos.push_back(i); fill_n(a,26,0); }
  }
  reverse(pos.begin(), pos.end());

  string result;
  int now = 0;
  rep(i,pos.size()) {
    // for (auto x: a) cout << x << " "; cout << endl;
    char c = 'a'; while (a[c-'a']) c++;
    result += c;
    if (i!=pos.size()-1) {
      while(A[now]!=c) now++;
      now++;
      // cout << now << endl;
      fill_n(a,26,0);
      while (now<pos[i+1]) { a[A[now]-'a']++; now++; }
    }
  }
  cout << result << endl;
  return 0;
}