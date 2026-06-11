#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}


void solve(){
  int n; cin >> n;
  int a[n];
  for(int i = 0; i < n; ++i) cin >> a[i];
  int ans[n];
  deque<int> an;
  
    for(int i = 0; i < n; ++i){
        if(n%2 == 0){
            if(i % 2 == 1) {
              an.push_front(a[i]);
            } else {
              an.push_back(a[i]);
          }
        } else {
            if(i % 2 == 0) {
              an.push_front(a[i]);
            } else {
              an.push_back(a[i]);
          }
        }
      }
      for(int i = 0; i < n; ++i){
          cout << an[i] << " ";
      }
      cout << endl;
      return;
  
}

int main(void){
    solve();
    return 0;
}
