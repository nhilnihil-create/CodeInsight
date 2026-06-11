#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
/* テンプレートここまで */

int main() {
  int N; cin >> N;
  vector<ll> a(3*N); REP(i, 3*N) cin >> a[i];

  multiset<int> st;

  //i=0,1,...,Nに対し，
  //a[0], a[1], ..., a[N-1+i]のうち，上位N個の和を記録
  vector<ll> former(N+1, 0); 
  //a[3N-1], a[3N-2], ..., a[2N-i]のうち，下位N個の和を記録
  vector<ll> latter(N+1, 0);

  REP(i, N){
    st.insert(a[i]);
    former[0] += a[i];
  }

  FOR(i, 1, N+1){
    auto min_it = st.begin();
    ll tmp = *min_it;
    if(a[N-1+i] > tmp){
      st.erase(min_it);
      st.insert(a[N-1+i]);
      former[i] = former[i-1] + a[N-1+i] - tmp;
    }else{
      former[i] = former[i-1];
    }
  }

  multiset<int> st2;

  REP(i, N){
    st2.insert(a[3*N-1-i]);
    latter[0] += a[3*N-1-i];
  }

  FOR(i, 1, N+1){
    auto max_it = st2.rbegin();
    ll tmp = *max_it;
    if(a[2*N-i] < tmp){
      //参考：http://izmiz.hateblo.jp/entry/2014/11/01/140233
      st2.erase(--max_it.base()); 
      st2.insert(a[2*N-i]);
      latter[i] = latter[i-1] + a[2*N-i] - tmp;
    }else{
      latter[i] = latter[i-1];
    }
  }

  ll ans = -INF;

  REP(i, N+1){
    ans = max(ans, former[i] - latter[N-i]);
  }

  cout << ans << endl;
}
