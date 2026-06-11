#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, m;
    cin >> n >> m;
    int x[200000] = {0} , y[200000] = {0};
    for (int i = 0 ; i < m ; i++ ) {
        int a , b;
        cin >> a >> b;
        if ( a == 1 ) x[b - 1] = 1;
        if ( b == n ) y[a - 1] = 1;
    }
    for (int i = 0 ; i < n ; i++ ) {
        if ( x[i] == 1 && y[i] == 1 ) {
            cout << "POSSIBLE";
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
  return 0;
}