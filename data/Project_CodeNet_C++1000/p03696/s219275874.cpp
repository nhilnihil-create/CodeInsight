#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N; string S;
  cin >> N >> S;
  int cnt=0;
  for (auto i:S) {
    if (i=='(') cnt++;
    else {
      cnt--;
      if (cnt<0) {
        cout << '(';
        cnt++;
      }
    }
    // cout << i;
  }
  cout << S;
  // rep(i,cnt) cout << ')';
  cout << string(cnt,')') <<endl;
} 