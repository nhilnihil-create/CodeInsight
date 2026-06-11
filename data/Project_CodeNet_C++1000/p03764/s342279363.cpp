#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

int n,m;

ll x[100001];
ll y[100001];
ll sumx[100001];
ll sumy[100001];

int main() {
  cin >> n >> m;

  for(int i = 0; i < n; i++) cin >> x[i];
  for(int j = 0; j < m; j++) cin >> y[j];
  
  sumx[0] = x[0];
  sumy[0] = y[0];

  for(int i = 1; i < n; i++) sumx[i] = sumx[i-1] + x[i];
 
  for(int i = 1; i < m; i++) sumy[i] = sumy[i-1] + y[i];
  

  ll tmp1 = 0;
  ll tmp2 = 0;

  for(int i = 1; i < n; i++) tmp1 += (sumx[n-1] - sumx[i-1]) - (n - i) * x[i-1];
  for(int i = 1; i < m; i++) tmp2 += (sumy[m-1] - sumy[i-1]) - (m - i) * y[i-1];
   

  cout << (tmp1 % mod) * (tmp2 % mod) % mod  << endl;
}
