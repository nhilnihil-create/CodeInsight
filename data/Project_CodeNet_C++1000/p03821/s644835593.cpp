#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
#define vpl vector<pair<long long,long long>>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
long long MOD = 1000000007;
const long double pi = 3.1415926535897932;
#define pb push_back
#define mp make_pair
#define mt make_tuple
//(mod m)でのaの逆元を計算する
//a/b(mod m)=a(mod m)*modinv(b,m)
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//コンビネーション
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}
//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//切り上げの割り算は(a + b - 1) / bでできる

//ここから
int main(){
    ll N;
    cin>>N;
    vl A(N);
    vl B(N);
    rep(i,N)cin>>A[i]>>B[i];
    ll count=0;
    rep(i,N){
        ll x=B[N-1-i]-A[N-1-i]%B[N-1-i];
        if(x==B[N-1-i]&&count==0){
            continue;
        }else if(x>=count){
            count=x;
        }else{
            ll y=(count-x+B[N-1-i]-1)/B[N-1-i];
            x+=B[N-1-i]*y;
            count=x;
        }
    }
    cout<<count<<endl;
}