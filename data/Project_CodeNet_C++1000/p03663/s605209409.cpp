#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }


int main() {
  ll dig = 1;
  char response = ' ';
  while (response!='N'&&dig<powl(10,10)) {
    dig *= 10;
    cout << "? " << dig << endl;
    cin >> response;
  }

  ll result = 0;
  if (dig!=powl(10,10)) {
    ll l = dig/100, r = dig/10-1;
    while (l!=r) {
      ll mid = (l+r+1)/2;
      cout << "? " << mid << endl;
      cin >> response;
      if (response=='Y') l = mid;
      else r = mid-1;
    }
    ll d10 = l*10, d1 = 10;
    response = ' ';
    while (response!='N'&&d1>0) {
      d1--;
      cout <<  "? " << (d10+(d1-1))*10 << endl;
      cin >> response;
    }
    result = d10+d1;
  }
  else {
    ll now = 1;
    response = ' ';
    while (response!='Y') {
      now *= 10;
      cout << "? " << now-1 << endl;
      cin >> response;
    }
    result = now/10;
  }

  cout << "! " << result << endl;
  return 0;
}