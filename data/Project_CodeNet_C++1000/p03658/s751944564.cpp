#include <bits/stdc++.h>
#define rep(i,a,n) for (int i=a; i<n; i++)
#define ll long long
#define MOD 1000000007
using namespace std;;
 
int main() {
  int N,K,ans =0; cin >> N >> K;
  int l[N]; rep(i,0,N) cin >> l[i];
  
  sort(l,l+N);
  rep(i,0,K) ans += l[N-i-1];    
  cout << ans << endl;
}