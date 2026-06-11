#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
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

  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;

  ll ans = 0;
  ll cnt = min({q*8, h*4, s*2, d});
  if(n % 2 == 0){
    ans += n/2 * cnt;
  }else{
    ans += n/2 * cnt;
    ll cnt2 = min({q*4, h*2, s});
    ans += cnt2;
  }
  cout << ans << endl;
  return 0;
}