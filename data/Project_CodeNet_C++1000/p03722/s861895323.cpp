#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;

int main() {

  int N, M;
  cin >> N >> M;
  vector<ll> dist(N,LINF);
  dist[0] = 0;

  vector<ll> a(M);
  vector<ll> b(M);
  vector<ll> c(M);

  REP(m,M){
    ll atmp, btmp, ctmp;
    vector<ll> vtmp(2);
    cin >> atmp >> btmp >> ctmp;
    atmp-=1, btmp-=1;
    ctmp = - ctmp;
    a[m] = atmp;
    b[m] = btmp;
    c[m] = ctmp;
  }


  REP(n,N){
    REP(m,M){
      ll atmp, btmp, ctmp;
      atmp = a[m];
      btmp = b[m];
      ctmp = c[m];
      if(dist[atmp] == LINF) continue;
      if (dist[btmp] > dist[atmp] + ctmp) dist[btmp] = dist[atmp] + ctmp;
    }
    
  }


  ll ans = dist[N-1];
  vector<bool> negative(N,false);

REP(n,N){
  REP(m,M){
    ll atmp, btmp, ctmp;
    atmp = a[m];
    btmp = b[m];
    ctmp = c[m];
    if (dist[atmp] == LINF) continue;

    if (dist[btmp] > dist[atmp] + ctmp){
      dist[btmp] = dist[atmp] + ctmp;
      negative[btmp] = true;
    }

    if (negative[atmp] == true) negative[btmp] = true;
  }
}

  if (negative[N-1]){
    cout << "inf" << endl;
  }else{
    cout << -ans << endl;
  }
}
