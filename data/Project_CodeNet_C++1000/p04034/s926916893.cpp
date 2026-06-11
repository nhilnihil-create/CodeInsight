#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const double PI = acos(-1);
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  vector<ll> cnt(n, 1);
  vector<pll> xy(m);
  for(ll i = 0; i < m; i++){
    cin >> xy[i].first >> xy[i].second;
    xy[i].first--, xy[i].second--;
  }

  vector<bool> yes(n);
  yes[0] = true;
  for(ll i = 0; i < m; i++){
    //cout << xy[i].first << ' ' << xy[i].second << endl;
    if(yes[xy[i].first]){
      yes[xy[i].second] = true;
      cnt[xy[i].first]--;
      cnt[xy[i].second]++;
    }else{
      if(cnt[xy[i].second] == 0) yes[xy[i].second] = false;
      cnt[xy[i].first]--;
      cnt[xy[i].second]++;
    }
  }

  ll ans = 0;
  for(ll i = 0; i < n; i++){
    if(yes[i] && cnt[i] > 0) ans++;
  }

  //for(auto i : cnt) cout << i << endl;
  //for(auto i : yes) cout << i << endl;
  cout << ans << endl;
  return 0;
}