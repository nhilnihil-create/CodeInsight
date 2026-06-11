#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <climits>
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<ll,ll> P;


ll N;
ll a[100100];
int main(){
  cin >> N;
  for(ll i=0;i<N;i++){
    cin >> a[i];
  }
  ll now_pos = 1;
  ll t=0;
  ll ans=1;
  for(ll i=0;i<N;i++){
    if(a[i] >= now_pos){
      a[i] = now_pos;
      now_pos+=2;
    }
    else{
      ans = (ans*(i+1-t)) % MOD;
      t++;
    }
  }
  for(ll i=1;i<=N-t;i++){
    ans = (ans*i) % MOD;
  }
  cout << ans << endl;
  /*
  ll b=0;
  ll c=0;
  ll d=0;
  ll num_count = 0;
  ll ans=1;
  ll now_pos = 0;
  for(ll i=0;i<N;i++){
    ll t = a[i] - now_pos;
    num_count++;
    if(t==1 && a[i]%2 == 0){
      b++;
      if(d>0){
        b--;
        d--;
      }
      else{
        ans =(ans*(num_count-c)) % MOD;
        c++;
      }
    }
    if(t>3){
      if(a[i]%2 == 0){
        d += (t-2)/2;
      }
      else{
        d += (t-1)/2;
      }
    }
    now_pos = a[i];
  }
  for(ll i=1;i<=num_count-c;i++){
    ans = (ans*i) % MOD;
  }
  cout << ans << endl;
  */
}
