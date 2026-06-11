#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n),b(100001,0);
  rep(i,n){
    cin >> a.at(i);
    b.at(a.at(i))++;
  }
  ll ans=0,maxi=0;
  for(int i=1;i<100000;i++){
    maxi=b.at(i-1)+b.at(i)+b.at(i+1);
    ans=max(ans,maxi);
  }
  cout << ans;
}