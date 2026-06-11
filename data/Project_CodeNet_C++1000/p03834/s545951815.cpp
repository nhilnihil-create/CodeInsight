#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
#define SZ(x) ((ll).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
const double PI = acos(-1);
const int mod = 1e9+7;
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}
template<class T>bool chmax(T &a, const T &b){ if(a < b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(a > b){ a=b; return 1; } return 0; }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  for(ll i = 0; i < s.size(); i++){
    if(s[i] == ',') s[i] = ' ';
  }
  cout << s << endl;
  return 0;
}