/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n, a, b, c, d;

int main(){
  cin >> n >> a >> b >> c >> d;
  int diff = b - a;
  for(int i = 0; i < n; ++i){
    int j = (n - i - 1);
    ll L = i * 1ll * -d + c * 1ll * j;
    ll R = i * 1ll * -c + d * 1ll * j;
    if(L <= diff && diff <= R){
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
