// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
//  cout.precision(15); cout << fixed;

typedef pair<ll, ll> P;

int main() {
  ll n, m; cin >> n >> m;
  map<int, int> M;
  loop(i,0,m) {
    int a, b;
    cin >> a >> b;
    M[a]++;M[b]++;
  }
  loop(i,1,n+1) {
    cout << M[i] << endl;
  }
  return 0;
}
