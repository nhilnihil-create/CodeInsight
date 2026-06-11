#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin>>s;
  int n=s.size();
  
  for (int i = n-1; i > 0; --i) {
    if(i%2!=0) continue;
    if(s.substr(0, i/2) == s.substr(i/2, i/2)) {
      cout<<i;
      return 0;
    }
  }
  
  return 0;
}