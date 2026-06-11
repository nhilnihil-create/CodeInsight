#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<ll,ll> P;

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
  rep(i,100001){
    if(i == 0) sum[i] = buc[i];
    else sum[i] = sum[i-1] + buc[i];
  }
  auto Iter =  lower_bound(sum.begin(),sum.end(),k);
  cout << Iter - sum.begin() << endl;
}