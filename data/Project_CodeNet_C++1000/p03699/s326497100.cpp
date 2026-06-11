#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<int> s(N);
  int ans=0;
  rep(i,0,N) {
    cin >>s[i];
    ans+=s[i];
  }
  if (ans%10) {
    cout <<ans <<endl;
    return 0;
  } else {
    sort(s.begin(),s.end());
    rep(i,0,N) {
      if (s[i]%10) {
        cout <<ans-s[i] <<endl;
        return 0;
      }
    }
  }
  cout <<0 <<endl;
  return 0;
}
