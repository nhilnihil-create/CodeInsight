#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define all(a) (a).begin(),(a).end()

int main(){
  int n; cin >> n;
  vi a(n); rep(i, n) cin >> a[i];
  // unique 真に unique にするための前処理で sort
  sort(all(a));
  a.erase(unique(all(a)), a.end());

  int ans = a.size();
  if(ans%2 == 0) ans--;

  std::cout << ans << '\n';
}
