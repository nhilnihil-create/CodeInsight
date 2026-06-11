#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
 
const double PI = 3.14159265358979323846;
/*Graph t;
void dfs(int v, int pv=-1){
    for(int vn: t[v]){
        if (vn == pv) continue;
        dfs(vn, v);
    }
}*/
int main() {
  ll n;
  cin >> n;
  ll k[n];
  rep(i,n)cin >> k[i];
  sort(k,k+n);
  ll z[n];
  z[0]=k[0];
  rep(i,n-1)z[i+1]=z[i]+k[i+1];
  ll ans=0;
  rep(i,n-1){
    if(z[i]*2<k[i+1])ans=i+1;
  }
  cout << n-ans << endl;
}
