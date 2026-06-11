#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll N,P,a=0,b=0,ans=1;
  cin >> N >> P;
  vector<ll> A(N);
  rep(i,N){
    cin >> A.at(i);
    A.at(i)%=2;
    if(A.at(i)==0){
      a++;
    }else{
      b++;
    }
  }
  ans*=(ll)pow(2,a);
  if(P==0){
    ll t=0,x=0;
    while(t<=b){
      ll y=1;
      rep(i,t){
        y*=b-i;
        y/=i+1;
      }
      x+=y;
      t+=2;
    }
    ans*=x;
    cout << ans << endl;
  }else{
    if(b==0){
      cout << 0 << endl;
      return 0;
    }
    ll t=1,x=0;
    while(t<=b){
      ll y=1;
      rep(i,t){
        y*=b-i;
        y/=i+1;
      }
      x+=y;
      t+=2;
    }
    ans*=x;
    cout << ans << endl;
  }
    
    
       
    
  

}