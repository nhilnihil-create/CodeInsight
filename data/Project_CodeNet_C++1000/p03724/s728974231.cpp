#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){
  int n, m;
  cin >> n >> m;
  map<int,int> mp;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    mp[a]++;
    mp[b]++;
  }
  for (auto e : mp) {
    if (e.second & 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}