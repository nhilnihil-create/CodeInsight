#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF=1000000007;

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<P> ab(n);
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    ab[i]=make_pair(a,b);
  }
  sort(ab.begin(),ab.end());
  ll sum=0;
  for(auto p : ab) {
    sum+=p.second;
    if(sum>=k) {
      cout << p.first << endl;
      return 0;
    }
  }
}
