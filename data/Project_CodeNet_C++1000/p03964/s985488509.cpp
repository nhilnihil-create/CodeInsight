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
      ll base_t=t,base_a=a;
      //ここ高速化
      ll prod = max(tmp_t/t,tmp_a/a);
      if(t*prod<tmp_t || a*prod<tmp_a) prod++;
      tmp_t = t*prod;
      tmp_a = a*prod;
      //cout << "tmpt" << tmp_t << "tmpa" << tmp_a << endl;
    }
  }
  cout << tmp_t + tmp_a << endl;
}