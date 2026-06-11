#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int, int> ii; 

ll f(ll a, ll b) {
  return !a ? -b : 2 * a * (b / a) + f(b % a, a); 
}

int main() {
  ll n, x; 
  cin >> n >> x; 
  cout << n + f(n - x, x) << endl; 
}