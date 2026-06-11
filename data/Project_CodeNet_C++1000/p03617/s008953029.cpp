#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll q,h,s,d,n;
  cin >> q >> h >> s >> d;
  cin >> n;
  q *=4;
  h *=2;
  s=min(min(q,h),s);
  if(n%2==0){
    cout << min(n*s,d*n/2) << endl;
  }
  else
    cout << min(n*s,d*(n-1)/2+s) << endl;
}