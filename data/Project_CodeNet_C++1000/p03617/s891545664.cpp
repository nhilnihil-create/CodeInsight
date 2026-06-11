#include<bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < (ll)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long unsigned int ll;
typedef vector<int >    vecint;
typedef vector<double >    vecd;
typedef vector<vector<int> >  vec2int;
typedef vector<vector<double> >  vec2d;
typedef vector<ll >     vecll;
typedef vector<string > vecstr;
typedef vector<bool > vecbool;
typedef vector<vector< bool > > vec2bool;
typedef vector<bool > vecbool;
////////////////////////////////////////////////
int main()
{
  ll q, h, s, d; cin >> q >> h >> s >> d;
  ll n; cin >> n;
  ll x = min(4*q, min(2*h, s));
  // cout << x << endl;
  if(2*x <= d){
    cout << n*x << endl;
  }else{
    cout << d*(n/2) + x*(n - 2*(n/2)) << endl;
  }
} 
