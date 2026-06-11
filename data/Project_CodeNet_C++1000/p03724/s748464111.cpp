#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;

int main()
{
  int n,m; cin>>n>>m;
  vector<int> v(100010, 0);
  rep(i, m) {
    int a,b; cin>>a>>b;
    v[a]++; v[b]++;
  }
  rep(i, 100001) {
    if (v[i]%2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;

  return 0;
}
