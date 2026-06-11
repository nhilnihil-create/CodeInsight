#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int C(ll x,int  y){
  ll ans=1;
  for(int i=x;i>x-y;i--){
    ans*=i;
  }
  for(int i=1;i<=y;i++){
    ans/=i;
  }
  return ans;
}

int main(){
  int n,p;
  cin >> n >> p;
  VI a(n);
  int od=0;
  rep(i,n){
      cin >>a.at(i);
      if(a.at(i)%2==1)od++;
  }
  ll ans;
  if(od==0){
    if(p==0)ans=pow(2,n);
    else if(p==1)ans=0;
  }
  else{
    ans=pow(2,n-1);
  }
  cout << ans << endl;
}