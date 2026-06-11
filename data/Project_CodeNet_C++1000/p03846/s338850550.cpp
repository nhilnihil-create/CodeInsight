#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) {
    cin >> a[i];
    if(n%2==a[i]%2 || a[i]>=n) {
      cout << 0 << endl;
      return 0;
    }
  }
  sort(ALL(a));
  if(a[0]!=0 && n%2==1){
    cout << 0 << endl;
    return 0;
  }
  rep(i,n-2){
    if(i==0 && n%2==1){
      if(a[i]==a[i+1]){
        cout << 0 << endl;
        return 0;
      }
    }
    if(a[i]==a[i+2]){
      cout << 0 << endl;
      return 0;
    }
  }
  
  ll ans = 1;
  rep(i,n/2){
    ans*=2;
    ans%=mod;
  }
  cout << ans << endl;
  
}
