#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;



  
int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  ll X1,X2;
  cin >> X1;
  ll ans = 0;
  rep(i,N-1){
    cin >> X2;
    ans += min((X2-X1)*A, B);
    X1 = X2;
  }
  
  cout << ans << endl;
    
}
      
       



