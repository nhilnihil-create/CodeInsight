#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

ll nextLong() { ll x; scanf("%lld", &x); return x;}

bool possible(const vector<ll>& A, ll s) {
  const int N = A.size();
  ll size = 0;
  REP(i, s+1) size += A[i];
  int pos = s + 1;
  while (pos < N && A[pos] <= 2 * size) {
    size += A[pos];
    pos++;
  }
  return pos == N;
}


int main2() {
  int N = nextLong();
  vector<ll> A(N);
  REP(i, N) A[i] = nextLong();
  sort(ALL(A));


  // for (int i = 0; i < N; i++) {
  //   cout << i << " " << possible(A, i) << endl;
  // }

  ll lo = -1;
  ll hi = N;
  while (hi - lo > 1) {
    ll mid = (hi + lo) / 2;
    if (possible(A, mid)) hi = mid; else lo = mid;
  }


  ll ans = N - hi;
  cout << ans << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}