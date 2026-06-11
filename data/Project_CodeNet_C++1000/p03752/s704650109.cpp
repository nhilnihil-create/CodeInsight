#include <iostream>
#include <vector>
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, s, n) for(ll i = s; i < n; i++)
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  
  ll min = 10000000000000;
  rep(i, 1<<(n-1)){
    int num = 0;
    vector<int> choice;
    rep(j, n-1){
      if (i>>j&1){
        num++;
        choice.push_back(j+1);
      }
    }
    if (num != k-1) continue;
    ll now = a[0];
    ll cash = 0;
    rep(j, num){
      rep2(x, 1, choice[j]){
        if (now < a[x])
          now = a[x];
      }
      if (now < a[choice[j]]){
        now = a[choice[j]];
      }
      else {
        now++;
        cash += now - a[choice[j]];
      }
    }
    if (cash < min)
      min = cash;
  }
  cout << min << endl;
  
  return 0;
}