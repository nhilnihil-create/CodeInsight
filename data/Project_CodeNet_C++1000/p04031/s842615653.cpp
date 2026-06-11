#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N; cin >> N;
  vi a(N);
  rep(i,N){ int d; cin >> d; a[i] = d;}
  int ave = 0;
  rep(i,N) ave += a[i];
  ave /= N;  
  int ans = 1e9+7;
  int tans = 0;
  for(int i = ave-1; i< ave+2; i++){
    rep(j,N) tans += (a[j]-i)*(a[j]-i);
    ans = min(ans, tans);
    tans = 0;
  }    
  cout << ans <<endl;
  return 0;
}