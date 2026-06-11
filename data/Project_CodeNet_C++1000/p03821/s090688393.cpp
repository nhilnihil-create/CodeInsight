#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const long double PI = acos(-1);
const long long INF = (1 << 30);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for(ll i = 0; i < n; i++) cin >> a[i] >> b[i];
  
  ll ans = 0;
  ll p = 0;
  for(ll i = n-1; i >= 0; i--){
    a[i] += p;
    ll d = b[i] - a[i] % b[i];
    if(d != b[i]){
      ans += d;
      p += d;
    }
  }
  cout << ans << endl;
  return 0;
}