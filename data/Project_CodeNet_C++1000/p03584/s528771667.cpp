#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll n,k;
  cin >> n >> k;
  ll a[n];
  ll b[n];
  rep(i,n)cin >> a[i] >> b[i];
  ll ans=0;
  ll u=0;
  rep(i,30){
    if(i==0)u=k;
    else if(k&(1<<i)){
      u=(k^(1<<i))|((1<<i)-1);
    }
    else continue;
    ll an=0;
    rep(j,n){
      if((u|a[j])==u)an+=b[j];
    }
    ans=max(ans,an);
  }
  cout << ans << endl;
}
