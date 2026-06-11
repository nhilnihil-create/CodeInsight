#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
#define SZ(x) ((ll).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repi(i, a, b) for(ll i = ll(a); i < ll(b); i++)
const double PI = acos(-1);
const int mod = 1e9+7;
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  ll odd = 0;
  cin >> n;
  rep(i, n){
    ll a;
    cin >> a;
    if(a % 2 == 1) odd++;
  }
  if(odd % 2 == 1) cout << "NO" << endl;
  else cout << "YES" << endl;
  return 0;
}