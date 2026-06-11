#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
  int n; cin >>n;
  vector<ll> a(n),b(n);
  rep(i,n) cin >>a[i] >>b[i];
  ll sum = 0;
  for(int i = n-1; 0<=i; i--){
    a[i]+=sum;
    sum += (b[i]-a[i]%b[i])%b[i];
  }
  cout << sum << endl;
  return 0;
}