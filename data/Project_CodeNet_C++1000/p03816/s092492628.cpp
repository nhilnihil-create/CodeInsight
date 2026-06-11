#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  ll count = 0;
  ll pre = -1;
  rep(i, n){
    if(pre != a[i]){
      pre = a[i];
      count++;
    }
  }
  ll ans = count;
  if((n - count) % 2 == 1) ans--;
  cout << ans << endl;
}