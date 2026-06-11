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
  int n;
  cin >> n;
  ll p=1000000007;
  int k[n];
  rep(i,n)cin >> k[i];
  int u[n];
  u[0]=0;
  rep(i,n-1)u[i+1]=max(u[i],i+1-(k[i]+1)/2);
  ll ans=1;
  rep(i,n){
    ans=(ans*(n-i-u[n-1-i]))%p;
  }
  cout << ans << endl;
}