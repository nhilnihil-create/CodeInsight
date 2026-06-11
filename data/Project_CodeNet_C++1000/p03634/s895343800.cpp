#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

vector<vpll> e;
int K;

void distance(int i,ll d,vl &dis) {
  dis[i]=d;
  rep(j,e[i].size()) {
    if(!dis[e[i][j].first]&&e[i][j].first!=K) distance(e[i][j].first,d+e[i][j].second,dis);
  }
}

int main() {
  int N;
  cin >> N;
  vi a(N-1),b(N-1),c(N-1);
  e=vector<vpll>(N);
  rep(i,N-1) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;b[i]--;
    pii x(b[i],c[i]),y(a[i],c[i]);
    e[a[i]].push_back(x);
    e[b[i]].push_back(y);
  }
  int Q;
  cin >> Q >> K;
  K--;
  vi x(Q),y(Q);
  rep(i,Q) {
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
  }
  
  vl dis(N);
  distance(K,0,dis);
  rep(i,Q) cout << dis[x[i]]+dis[y[i]] << endl;
}