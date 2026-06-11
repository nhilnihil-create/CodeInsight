#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s; cin>>s;
  
  char v = s[0];
  int divCount = 0;
  
  rep(i, s.length()) {
    if (s[i]==v) continue;
    
    v=s[i];
    ++ divCount;
  }
  
  cout<<divCount;
  
  return 0;
}