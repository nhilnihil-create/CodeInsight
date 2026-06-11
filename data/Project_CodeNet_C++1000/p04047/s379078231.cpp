#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

int main() {
  int N;
  cin >> N;
  vi L(2*N);
  rep(i,2*N) cin >> L[i];
  sort(L.begin(),L.end());
  int ans=0;
  rep(i,N) ans+=L[2*i];
  cout << ans << endl;
}