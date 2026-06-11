#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1000000000000000000

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  ll m = INF;
  for (int i = -100; i < 101; i++){
    ll sum = 0;
    for (int j = 0; j < n; j++){
      sum += (a[j] - i) * (a[j] - i);
    }
    if (sum < m){
      m = sum;
    }
  }

  cout << m << endl;

  return 0;
}
