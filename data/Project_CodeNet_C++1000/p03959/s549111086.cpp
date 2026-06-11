#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n;
  cin >> n;
  ll t[n];
  ll a[n];
  rep(i,n)cin >> t[i];
  rep(i,n)cin >> a[i];
  ll mi[n];
  ll ma[n];
  mi[0]=t[0];
  ma[0]=t[0];
  if(t[n-1]!=a[0]){
    cout << 0 << endl;
    return 0;
  }
  rep(i,n-1){
    if(t[i]==t[i+1]){
      mi[i+1]=1;
      ma[i+1]=t[i];
    }
    else{
      mi[i+1]=t[i+1];
      ma[i+1]=t[i+1];
    }
  }
  ll ans=1;
  ll p=1000000007;
  rep(i,n-1){
    int y=n-1-i;
    ll mii,maa;
    if(a[y]==a[y-1]){
      mii=1;
      maa=a[y];
    }
    else{
      mii=a[y-1];
      maa=a[y-1];
    }
    if(mii>ma[y-1]||mi[y-1]>maa){
      cout << 0 << endl;
      return 0;
    }
    else{
      ans=(ans*max((ll)0,(1+min(min(ma[y-1]-mii,maa-mi[y-1]),min(maa-mii,ma[y-1]-mi[y-1])))))%p;
      //cout << y-1 <<  " " <<  ans << endl;
    }
  }
  cout << ans << endl;
  /*ll m=8848;
  ll z=3776;
  cout << m*m*m%p*z%p << endl;*/
}
