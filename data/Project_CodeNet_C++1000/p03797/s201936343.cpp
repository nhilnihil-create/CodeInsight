#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ll n, m;
  cin >> n >> m;
  if(n*2>=m) cout << m/2 << endl;
  else cout << n + (m-(ll)2*n)/(ll)4 << endl;
  return 0;
}