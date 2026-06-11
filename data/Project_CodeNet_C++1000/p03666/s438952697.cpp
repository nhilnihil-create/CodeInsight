#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
ll n;
 cin>>n;
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  
  ll dis=b-a;
  for(int p=0;p<=n-1;p++){
    ll q=n-1-p;
    ll dismax=d*p-c*q;
    ll dismin=c*p-d*q;
    if(dismin<=dis&&dis<=dismax){
      cout<<"YES"<<endl;
      return 0;}
  }
  
  cout<<"NO"<<endl;
  return 0;
    
  
  
}
