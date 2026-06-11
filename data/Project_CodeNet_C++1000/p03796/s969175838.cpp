#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll; // long long型をこのように定義することで時間短縮

int main() {
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  ll ans = 1; //long long型にしておく
  for(int i=1; i<=n; i++){
    ans = ans*i%MOD; //掛け算一回ごとにあまりをとる
  }
  cout << ans << endl;
}
