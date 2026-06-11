#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vi x(n);
  ll ans = 0;
  rep(i, n){
    cin >> x[i];
    if(i){
      ll kyori = abs(x[i] - x[i - 1]);
      ans += min(kyori * a, b);
    }
  }
  cout << ans << endl;
}