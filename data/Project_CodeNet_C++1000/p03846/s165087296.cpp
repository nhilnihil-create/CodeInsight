#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
 
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define popcount(x) __builtin_popcountll(x)
 
const long double PI = acos(-1);
 
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  for(ll i = 0; i < n; i++){
    cin >> a[i];
    mp[a[i]]++;
  }

  ll ans = 1;
  if(n % 2 == 0){
    for(ll i = 1; i < n; i += 2){
      if(mp[i] != 2){
        cout << 0 << endl;
        return 0;
      }else{
        ans *= 2;
        ans %= mod;
      }
    }
  }else{
    if(mp[0] != 1){
      cout << 0 << endl;
      return 0;
    }
    for(ll i = 2; i < n; i += 2){
      if(mp[i] != 2){
        cout << 0 << endl;
        return 0;
      }else{
        ans *= 2;
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}