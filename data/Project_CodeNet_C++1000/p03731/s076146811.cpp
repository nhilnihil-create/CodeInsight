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
  ll n,time;
  cin >> n >> time;
  ll ans = 0;
  ll now = 0;
  rep(i,n){
    int touch;
    cin >> touch;
    if(touch < now){
      int pre = now;
      now = touch + time;
      ans += now - pre;
    }
    else{
      now = touch + time;
      ans += time;
    }
  }
  cout << ans << endl;
}