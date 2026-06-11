#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
#include <bitset>
using namespace std;
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0個の丸と-1個の棒みたいな時に時に効く？不安.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  ret *= kaijo(n); ret %= MOD;
  ret *= gyaku_kaijo(r); ret %= MOD;
  ret *= gyaku_kaijo(n-r); ret %= MOD;
  return ret;
}

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  n -= 1;

  if(a >= b){
    swap(a,b);
  }
  ll yoyu = 0;
  while(n > 0 && a < b){
    a += d;
    n--;
    yoyu += d - c;
  }
  if(n == 0 && a < b){
    cout<<"NO"<<endl;
    return 0;
  }
  if(n%2 == 0){
    if(a - yoyu <= b){
      cout<<"YES"<<endl;
      return 0;
    }else{
      a -= yoyu;
      swap(a,b);
      if(a + (d-c) * (n/2) >= b){
        cout<<"YES"<<endl;
        return 0;
      }else{
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }else{
    a -= d;
    yoyu -= d-c;
    n++;

    if(a + (d-c) * (n/2) >= b){
      //cout<<n<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
      cout<<"YES"<<endl;
      return 0;
    }

    a += d*2;
    yoyu += (d-c) * 2;
    n--;n--;
    if(a - yoyu <= b){
      cout<<"YES"<<endl;
      return 0;
    }else{
      a -= yoyu;
      swap(a,b);
      if(a + (d-c) * (n/2) >= b){
        cout<<"YES"<<endl;
        return 0;
      }else{
        cout<<"NO"<<endl;
        return 0;
      }
    }
  }
  return 0;
}