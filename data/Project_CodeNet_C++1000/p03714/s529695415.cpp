#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define print(x) cout << (x) << endl;
#define sz(x) int(x.size())
 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll LLINF = 1LL<<60;
const int INF = 1<<29;
const int MOD = 1000000007;
 
void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
 
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

ll num[30];
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(10);
    int N; cin >> N;
    vector<ll> a(N*3);
    rep(i,N*3) cin >> a[i];

    // 左から前処理
    vector<ll> S(N*2+1, 0);
    priority_queue<ll, vector<ll>, greater<ll> > que1;
    rep(i,N){
      S[i+1] = S[i] + a[i];
      que1.push(a[i]);
    }
    REP(i, N, N*2){
      ll mi = que1.top();
      if(a[i] > mi){
        S[i+1] = S[i] - mi + a[i];
        que1.pop();
        que1.push(a[i]);
      }
      else S[i+1] = S[i];
    }

    // 右から前処理
    vector<ll> T(N*2+1, 0);
    priority_queue<ll> que2;
    rep(i,N){
      T[i+1] = T[i] + a[N * 3 - 1 - i];
      que2.push(a[N * 3 - 1 - i]);
    }
    REP(i,N,N*2){
      ll ma = que2.top();
      if(a[N * 3 - 1 - i] < ma){
        T[i+1] = T[i] - ma + a[N*3-1 - i];
        que2.pop();
        que2.push(a[N * 3 - 1 - i]);
      }
      else T[i+1] = T[i];
    }

    ll ans = -(1LL << 60);
    REP(i,N,N*2+1){
      ans = max(ans, S[i] - T[N*3-i]);
    }
    cout << ans << endl;

}