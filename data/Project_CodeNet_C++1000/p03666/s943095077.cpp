#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
signed main(){
  ll n,a,b,c,d,val0,val1;
  bool can=false;
  cin >> n >> a >> b >> c >> d;
  for(int i=0;i<n;i++){
    val0 = c*(n-1-i) - d*i; 
    val1 = -c*i + (n-1-i)*d; 
    if(val0<=(b-a)&&(b-a)<=val1){
      can = true;
      break;
    }
  }
  if(can){
    cout <<"YES\n";
  }else{
    cout <<"NO\n";
  }
}
