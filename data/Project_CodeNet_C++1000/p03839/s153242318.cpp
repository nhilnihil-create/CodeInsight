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
  int n,k;
  cin >> n >> k;
  ll a[n];
  rep(i,n)cin >> a[i];
  ll b[n+1];
  b[0]=0;
  rep(i,n)b[i+1]=b[i]+a[i];
  ll c[n+1];
  c[0]=0;
  rep(i,n)c[i+1]=max((ll)0,a[i])+c[i];
  ll ans=0;
  rep(i,n-k+1){
    ans=max(ans,max((ll)0,b[i+k]-b[i])+c[n]+c[i]-c[i+k]);
  }
  cout << ans << endl;
}
