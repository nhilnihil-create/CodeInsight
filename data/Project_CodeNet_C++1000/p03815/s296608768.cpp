#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000


ll gcm(ll a,ll b);
ll lcm(ll a,ll b);
ll fac(ll a);

int main(){
  ll x;
  cin >> x;
  ll ans = 0;
  ans = x / 11 * 2;
  x %= 11;
  if(x >= 6){
    x -= 6;
    ans++;
  }
  if(x >= 1){
    x -= 5;
    ans++;
  }
  cout << ans << endl;
}