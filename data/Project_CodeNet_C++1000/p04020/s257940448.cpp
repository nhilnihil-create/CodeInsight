
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define ll_1e9 (ll)1e9
using namespace std;

int main(){
  ll n,cnt = 0;
  cin >> n;
  ll memo = 0,a = 0;
  rep(i,0,n){
    cin >> a;
    cnt += (a+memo)/2;
    memo = (a+memo) % 2;
    if(!a) memo = 0;
  }


  cout << cnt << endl;
  return 0;
}