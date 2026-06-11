#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)


int main() {
  int N;
  ll a;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }

  ll ans=1;
  int cnt=2;
  sort(A.rbegin(),A.rend());
  rep(i,N) {
    if (i==N-1) break;
    if (A[i]==A[i+1]) {
      ans*= A[i];
      cnt--;
      if (cnt==0) {
        cout << ans << endl;
        return 0;
      }
      i++;
      }
  }
  cout << 0 << endl;
}