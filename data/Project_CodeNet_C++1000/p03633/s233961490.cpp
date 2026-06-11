#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i,n){
    cin >> t.at(i);
  }
  sort(t.begin(),t.end());
  rep(i,n-1){
    for(int j=i+1;j<n;j++){
      if(t.at(j)%t.at(i)==0){
        t.at(i)=1;
        break;
      }
    }
  }
  ll ans=1;
  rep(i,n){
     ans=ans/__gcd(ans,t.at(i))*t.at(i);
  }
  cout << ans << endl;
}