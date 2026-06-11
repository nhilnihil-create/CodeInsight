#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if(a==b&&b==c&&a%2==0){
    cout<<-1<<endl;
    return 0;
  }
  int cnt = 0;
  while (1) {
    if ((a % 2 | b % 2 | c % 2 )== 1) break;
    ll A = a, B = b, C = c;
    a = (B + C) / 2;
    b = (A + C) / 2;
    c = (A + B) / 2;
    cnt++;
    //cout << a << b << c << endl;
  }
  cout << cnt << endl;

  return 0;
}
