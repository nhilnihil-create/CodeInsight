#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vp;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }

const ll INF=99999999999999;
const ll MOD=1000000007;
const ll MAX_C = 60;
ll Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]);
        }
    }
}
 
int main() {
  calc_com();
  ll n,a,b;
  cin >> n >> a >> b;
  vl v(n);
  rep(i,n) cin >> v[i];
  sort(ALL(v));
  ll num = v[n-a];
  ll sum = 0;
  for(ll i = n-a; i<n; i++){
    sum += v[i];
  }
  double s,A;
  s = (double)sum;
  A = (double)a;
  double x = s/A;
  cout << setprecision(10) << x << endl;
  ll cnt1 = 0, cnt2 = 0;
  rep(i,n){
    if(v[i] == num) cnt1++;
    if(v[i] > num) cnt2++;
  }
  if(cnt1 == 1){
    cout << 1;
    return 0;
  }
  ll ans = 0;
  if(num == v[n-1]){
  for(ll i=a; i<=b; i++){
    ans += Com[cnt1][i];
  }
  } else {
    ans = Com[cnt1][a-cnt2];
  }
  cout << ans;
 return 0;
}