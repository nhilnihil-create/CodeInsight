#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int add(int x,int y) {
  return x + y >= mod ? x + y - mod : x + y;
}

inline int mul(int x,int y) {
  return (ll) x * y % mod;
}

int ans,n,m,x[N],y[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1 ; i <= n ; i++)
    cin >> x[i];
  for (int i = 1 ; i <= m ; i++)
    cin >> y[i];
  sort(x + 1,x + n + 1);
  sort(y + 1,y + m + 1);
  int temp = 0;
  for (int i = 2 ; i <= m ; i++)
    temp = add(temp,mul(y[i] - y[i - 1],mul(m - i + 1,i - 1)));
  for (int i = 2 ; i <= n ; i++)
    ans = add(ans,mul(mul(temp,mul(n - i + 1,i - 1)),x[i] - x[i - 1]));
  cout << ans << endl;
}