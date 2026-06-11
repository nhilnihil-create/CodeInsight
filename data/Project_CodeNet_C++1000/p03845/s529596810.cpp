#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N; cin >> N;
  vi T(N);
  rep(i,N){int a; cin >> a; T[i] = a;}
  int M; cin >> M;
  vvi chg(M, vi(2));
  rep(i,M){ int a, b; cin >> a >> b; chg[i][0]=a; chg[i][1]=b;}
  int tsum = 0;
  rep(i,N) tsum += T[i];

  rep(i,M) cout << tsum - T[chg[i][0]-1] + chg[i][1] << endl;
  return 0;
}