#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair< ll, ll > Pi;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
const ll INF = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a,b)*b;}
#define all(x) x.begin(), x.end()
#define mp make_pair
bool compare(Pi a, Pi b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}


bool In_map(ll y,ll x,ll h,ll w){
    if(y<0 || x<0 || y>=h || x>=w){
        return 0;
    }else{
        return 1;
    }
}
const vector<ll> dx{1,0,-1,0};
const vector<ll> dy{0,1,0,-1};

const int MAX = 100;
#define MOD 10000000

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
ll combination(ll n, ll r) {
  if ( r * 2 > n ) r = n - r;
  ll dividend = 1;
  ll divisor  = 1;
  vector<bool>flag(r+1);
  for ( ll i = 1; i <= r; ++i ) {
    dividend *= (n-i+1);
    if(dividend)
    //divisor  *= i;
    rep2(j,r){
        if(dividend%j==0 && flag[j]==0){
            dividend/=j;
            flag[j]=1;
        }
    }
  }
  return dividend;
}
int main() {
    COMinit();
    ll N,A,B;
    cin >>N>>A>>B;

    vector<ll>v(N);
    rep(i,N){
        cin>>v[i];
    }

    sort(all(v),greater<ll>());
    double ans1=0;
    vector<ll>mx(A);
    vector<ll>res(N-A);
    rep(i,A){
        mx[i]=v[i];
        ans1+=v[i];
    }
    rep(i,N-A){
        res[i]=v[A+i];
    }
    ll mn=mx[A-1];
    ll cnt1=0;
    rep(i,A){
        if(mx[i]==mn){
            cnt1++;
        }
    }
    ll cnt2=0;
    rep(i,N-A){
        if(res[i]==mn){
            cnt2++;
        }
    }
    //cout<<combination(50,1)<<endl;
    //cout<<cnt1<<" "<<cnt2<<endl;
    ll ans=0;
    if(cnt1==A){
        for(ll i=A;i<=min(B,cnt1+cnt2);i++){
            ans+=combination(cnt1+cnt2,i);
            //cout<<i<<endl;
            //cout<<combination(cnt1+cnt2,i)<<endl;
        }
    }else{
        ans=combination(cnt1+cnt2,cnt1);
    }
    cout << fixed << setprecision(15) << ans1/double(A) << endl;

    cout << ans << endl;

    return 0;
    

}