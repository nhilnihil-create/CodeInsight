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

  ll n;
  string s;
  cin >> n >> s;

  ll l = 0, r = 0;
  for(ll i = 0; i < n; i++){
    if(s[i] == '(') r++;
    else{
      if(r == 0) l++;
      else r--; 
    }
  }
  
  string t = "";
  for(ll i = 0; i < l; i++) t += '(';
  t += s;
  for(ll i = 0; i < r; i++) t += ')';
  cout << t << endl;
  return 0;
}