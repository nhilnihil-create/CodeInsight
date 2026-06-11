#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n;
  cin >> n;
  vector < ll > r(n + 1);
  for(int i = 1; i <= n; i++){
    ll p;
    cin >> p;
    r[p] = i;
  }

  const ll p = 3e4;
  for(int i = 1; i <= n; i++){
    cout << p * i << " ";
  }
  cout << '\n';
  for(int i = 1; i <= n; i++){
    ll b = p * (n - i) + r[i];
    cout << b << " ";
  }
  cout << '\n';
}
