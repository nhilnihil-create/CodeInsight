#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll a, b, c;
  cin >> a >> b >> c;
  
  ll d, e, f;
  cin >> d >> e >> f;
  
  vector<int> tukureru(f + 1, 0);
  for (int i = 0; i < f + 1; i++){
    for (int j = 0; j < f + 1; j++){
      if (c * i + d * j > f){
        break;
      }
      tukureru[c * i + d * j] = c * i + d * j;
    }
  }
  for (int i = 1; i <= f; i++){
    if (tukureru[i] == 0){
      tukureru[i] = tukureru[i-1];
    }
  }


  double noudo = 0;
  ll mizu, sato;
  int ok = 0;
  for (int i = 0; i <= 30; i++){
    for (int j = 0; j <= 30; j++){
      ll m = min(f - 100*a*i - 100*b*j, (a*i + b*j)*e);
      if (m < 0){
        break;
      }
      if (!ok && (i != 0 || j != 0)){
        mizu = 100*a*i + 100*b*j;
        sato = 0;
        ok = 1;
      }
      ll n = tukureru[m];
      double nownoudo = 100.0 * n / (100*a*i + 100*b*j + n);
      if (nownoudo > noudo){
        noudo = nownoudo;
        mizu = 100*a*i + 100*b*j;
        sato = n;
      }
    }
  }

  cout << mizu + sato << " " << sato << endl;

  return 0;
}
