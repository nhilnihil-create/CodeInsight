#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  
  if (a[0] >= 3200){
    cout << 1 << " " << n << endl;
  }
  else {
    int hoge[9] = {};
    for (int i = 0; i < n; i++){
      int m = min(a[i]/400, 8LL);
      hoge[m]++;
    }
    int sum = 0;
    for (int i = 0; i < 8; i++){
      sum += min(1, hoge[i]);
    }

    cout << sum << " " << sum + hoge[8] << endl;
  }

  return 0;
}
