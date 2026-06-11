#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  b-=a;
  int u=0;
  rep(i,n){
    ll ma=d*i-c*(n-i-1);
    ll mi=c*i-d*(n-i-1);
    if(ma>=b&&mi<=b)u++;
  }
  if(u==0)cout << "NO" << endl;
  else cout << "YES" << endl;
}