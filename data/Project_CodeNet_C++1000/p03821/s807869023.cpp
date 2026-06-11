#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n){
    int x, y;
    cin >> x >> y;
    a[i] = x; b[i] = y;
  }
  ll cnt = 0;
  for(int i=n-1; i>=0; i--){
    if((a[i]+cnt) % b[i] != 0){
      cnt += b[i] - (a[i]+cnt) % b[i];
    }
  }
  cout << cnt << endl;
  return 0;
}
  
  