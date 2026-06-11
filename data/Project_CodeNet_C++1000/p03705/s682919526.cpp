#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,a,b; cin >> n >> a >>b;
  if(n==1 && a!=b){
    cout << 0 << endl;
    return 0;
  }
  else if(n==1 && a==b){
    cout << 1 << endl;
    return 0;
  }
  else{
  n-=2;
  if(a>b){
    cout << 0 << endl;
    return 0;
  }
  ll ans=b*n-a*n+1;

  cout << ans << endl;
 }
}
