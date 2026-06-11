#include <bits/stdc++.h>
#define rep(i,a,n) for (int i = a; i < (int)(n); i++)
#define ll long long
using namespace std;

int main() {
  ll N; cin >> N;
  ll tmp = sqrt(N); int ans = 11;
  rep(i,1,tmp+1) {
    if (N % i ==0) {
      ll tmp = max((ll)i,N / i);
      int a =0;
      while (tmp !=0) {
        a++;
        tmp /= 10;
      }   
      ans = min(a,ans);
    }
  }
  cout << ans << endl;
}