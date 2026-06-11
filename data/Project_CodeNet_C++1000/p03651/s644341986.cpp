#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009

ll gcm(ll a,ll b){
  if(a < b) swap(a,b);
  if(b == 0) return a;
  return gcm(a%b,b);
}

int main(){
  ll n,k;
  cin >> n >> k;
  ll b;
  cin >> b;
  ll ag = b;
  rep(i,n){
    ll a;
    cin >> a;
    ag = gcm(ag,a);
    b = max(b,a);
  }
  if(k <= b && k % ag == 0) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
