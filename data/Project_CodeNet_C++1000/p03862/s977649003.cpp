#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  int n, x; cin >> n >> x;
  vector<ll> a(n);
  ll cnt = 0;

  for(int i=0; i<n; i++)  cin >> a.at(i);
  for(int i=0; i<n-1; i++){
    if(a[i]+a[i+1]<=x) continue;
    cnt += a[i+1]+a[i]-x;
    a[i+1] = max(0LL, x-a[i]);
  }
  cout << cnt << endl;
}
