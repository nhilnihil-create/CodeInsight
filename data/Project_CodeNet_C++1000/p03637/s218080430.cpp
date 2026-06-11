#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  int n;
  cin >> n;
  vll a(n);
  rep(i,n) cin >> a.at(i);
  vi b(n);
  rep(i,n) {
    if(a[i]%2==1) b[i] = 0;
    else {
      a[i] /= 2;
      if(a[i]%2==1) b[i] = 1;
      else b[i] = 2;
    }
  }
  int cnt0 = 0;
  int cnt2 = 0;
  rep(i,n) {
    if(b[i]==0) cnt0++;
    if(b[i]==2) cnt2++;
  }
  if(cnt0<=cnt2) cout << "Yes" << endl;
  else if(cnt0==cnt2+1 && cnt0+cnt2==n) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}