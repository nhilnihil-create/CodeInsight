#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  ll n,k;
  cin >> n >> k;
  vector<ll> buc(100001);
  rep(i,n){
    ll a,b;
    cin >> a >> b;
    buc[a] += b;
  }
  vector<ll> sum(100001);
  rep1(i,100000){
    if(i == 1) sum[i] = buc[i];
    else sum[i] = sum[i-1] + buc[i];
  }
  cout << lower_bound(all(sum),k)-begin(sum) << endl;
}