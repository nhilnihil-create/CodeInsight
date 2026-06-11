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

int nextInt() { int x; scanf("%d", &x); return x;}
ll nextLong() { ll x; scanf("%lld", &x); return x;}

const ll MOD = (ll)(1e9 + 7);

const int MAX_N = 1123456;
ll dp[MAX_N];
ll S[MAX_N];

int main2() {
  ll N = nextInt();
  ll M = N;

  dp[0] = 0;
  dp[1] = M;
  dp[2] = M * M % MOD;

  S[0] = 0;
  S[1] = dp[1];
  S[2] = (S[1] + dp[2]) % MOD;

  for (int n = 3; n <= N; n++) {
    ll val = 0;
    val += dp[n-1];
    val += (M-1)*(M-1) % MOD;

    if (n == 3) {
      val += M-1;
    } else {
      val += S[n-3];
      val += max(0LL, -n+M+2);
    }

    val %= MOD;
    dp[n] = val;
    S[n] = (S[n-1] + dp[n]) % MOD;
  }
  ll ans = dp[N];
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
