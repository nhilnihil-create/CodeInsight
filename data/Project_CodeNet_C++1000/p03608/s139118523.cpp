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
void wf(vector<vector<ll>> &k){
  int n=k.size();//存在しない辺をinfで渡す
  rep(o,n)rep(i,n)rep(j,n)k[i][j]=min(k[i][j],k[i][o]+k[o][j]);
  //rep(i,n)rep(j,n)rep(o,n)k[i][j]=min(k[i][j],k[i][o]+k[o][j]);
}
int main(){
  int n,m,r;
  cin >> n >> m >> r;
  vector<int> u(r,0);
  rep(i,r){
    int y;
    cin >> y;
    y--;
    u[i]=y;
  }
  vector<vector<ll>> k(n,vector<ll>(n,100000000000000000));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    ll c;
    cin >> c;
    k[a][b]=c;
    k[b][a]=c;
  }
  wf(k);
  //rep(i,n)rep(j,n)cout << k[i][j] << endl;
  int a[r];
  rep(i,r)a[i]=i;
  ll ans=2000000000000000000;
  do {
   //cout << a[0] << a[1] << a[2] << ans << endl;
    ll p=0;
    rep(i,r-1){
      //cout << k.at(u[a[i]]).at(u[a[i+1]]) << u[a[i]] << u[a[i+1]] << endl;
      p+=k.at(u[a[i]]).at(u[a[i+1]]);
    }
    if(p<0){
      while(true){
        p++;
      }
    }
    ans=min(ans,p);
  } while(next_permutation(a, a + r));
  cout << ans << endl;
}
