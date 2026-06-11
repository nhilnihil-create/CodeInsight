#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  vector<ll> a(3*n);

  for (int i = 0; i < 3*n; i++){
    cin >> a[i];
  }

  //前半の大きいものを格納
  priority_queue<ll, vector<ll>, greater<ll>> Q1;
  vector<ll> m1(n + 1, 0);
  for (int i = 0; i < n; i++){
    Q1.push(a[i]);
    m1[0] += a[i];
  }

  // 後半の小さいものを格納
  priority_queue<ll> Q2;
  vector<ll> m2(n + 1, 0);
  for (int i = 0; i < n; i++){
    Q2.push(a[i + 2*n]);
    m2[n] += a[i + 2*n];
  }



  for (int i = 1; i <= n; i++){
    Q1.push(a[i + n - 1]);
    m1[i] = m1[i - 1] + a[i + n - 1] - Q1.top();
    Q1.pop();
  }

  for (int i = 1; i <= n; i++){
    Q2.push(a[2*n - i]);
    m2[n-i] = m2[n - i + 1] + a[2*n - i] - Q2.top();
    Q2.pop();
  }
 
  ll res = -INF;
  for (int i = 0; i <= n; i++){
    res = max(res, m1[i] - m2[i]);
  }
  cout << res << endl;



  return 0;
}
