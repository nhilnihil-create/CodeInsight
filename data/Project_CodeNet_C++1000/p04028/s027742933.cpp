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

const ll MOD = (ll)(1e9 + 7);

ll dp[5005][5005];


ll mod_pow(ll a, ll b, ll p) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res;
}

ll mod_inv(ll a, ll p) {
  return mod_pow(a % p, p - 2, p);
}


int main2() {
  CLR(dp, 0);
  int N; cin >> N;
  string s; cin >> s;
  dp[0][0] = 1;
  for (int n = 1; n <= N; n++) {
    for (int l = 0; l <= N; l++) {
      ll res = 0;
      res += dp[n-1][l+1]; // backspace
      if (l == 0) res += dp[n-1][l]; // backspace
      if (l - 1 >= 0) res += dp[n-1][l-1] * 2; // 0, 1
      dp[n][l] = res % MOD;
    }
  }
  ll ans = dp[N][s.size()];
  ll inv2 = mod_inv(2, MOD);
  REP(i, s.size()) (ans *= inv2) %= MOD;
  cout << ans << endl;
  return 0;
}

int main() {
  for (;!cin.eof();cin>>ws)
    main2();
  return 0;
}
