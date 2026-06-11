#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
int main() {
  cout << fixed << setprecision(10);
  vector<bool> a(100000);
  int n;
  cin >> n;
  rep(i,n){
    int l,r;
    cin >> l >> r;
    l--; r--;
    for(int i = l; i<=r; i++){
      a.at(i)=true;
    }
  }
  int ans = 0;
  rep(i,100000){
    if(a.at(i)){
      ans++;
    }
  }
  cout << ans << endl;
}
