#include <bits/stdc++.h>
#define FOR(x,n) for(int x = 0; x < n; x++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
  int N; cin >> N;
  
  ll a = 0, b = 0;
  FOR(x,N) {
    ll S, T; cin >> S >> T;
    if(S*(b/T+(b%T!=0)) >= a)
      a = S*(b/T+(b%T!=0)), b = (b/T+(b%T!=0))*T;
    else
      a = (a/S+(a%S!=0))*S, b = T*(a/S);
    if(x == 0) a = S, b = T;
  }
  
  cout << a + b << "\n";
}
