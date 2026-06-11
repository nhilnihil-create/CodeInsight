#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  int a[110000];
  ll ans = 0;
  for(int i = 0; i < n; i++) cin >> a[i];
  if(a[0] > x){
    ans += a[0] - x;
    a[0] = x;
  }
  for(int i = 0; i < n-1; i++){
    if(a[i] + a[i+1] > x){
      ans += a[i+1] + a[i] - x;
      a[i+1] = x - a[i];
    }
  }
  cout << ans <<endl;
}
