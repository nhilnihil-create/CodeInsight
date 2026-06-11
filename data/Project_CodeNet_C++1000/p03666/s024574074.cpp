#include <iostream>
using namespace std;

typedef long long ll;

int main(){
  ll n,a,b,c,d;
  cin >> n >> a >> b >> c >> d;
  ll dis=b-a;
  bool ans=false;
  for(ll i=0;i<n;i++){
    ll max_dis=d*i-c*(n-1-i);
    ll min_dis=c*i-d*(n-1-i);
    if(min_dis<=dis&&dis<=max_dis){
      ans=true;
    }
  }
  cout << (ans?"YES":"NO") << endl;
}