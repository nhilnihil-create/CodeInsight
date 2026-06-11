#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
using vs = vector<string> ;
#define all(v) v.begin(),v.end()

int main(){
  ll N;cin>>N;
  ll tmp_t,tmp_a;cin>>tmp_t>>tmp_a;
  ll ans=0;
  rep(i,N-1){
    ll t,a;cin>>t>>a;
    if(tmp_t*a==tmp_a*t) continue;
    else {
      ll prod = max((tmp_t+t-1)/t,(tmp_a+a-1)/a);
      tmp_t = t*prod;
      tmp_a = a*prod;
    }
  }
  cout << tmp_t + tmp_a << endl;
}