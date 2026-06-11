#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll N; cin >> N;
  vector<ll> p(N);
  REP(i,N){
    cin >> p[i];
    p[i]--;
  }
  vector<ll> a(N), b(N);
  REP(i,N){
    a[i] = (i+1)*N;
    b[i] = (N-i)*N;
  }
  REP(i,N-1){
    if(p[i]<p[i+1]) a[p[i+1]] += i+1;
    else b[p[i+1]] += i+1;
  }
  REP(i,N) cout << a[i] << " \n"[i==N-1];
  REP(i,N) cout << b[i] << " \n"[i==N-1];
}