#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  ll n,c,k;
  cin >> n >> c >> k;

  vector<ll> t(n);
  rep(i,n) cin >> t.at(i);
  sort(t.begin(), t.end());

  ll time=t.at(0)+k,pass=0,bus=0;
  rep(i,n){
    if(time>=t.at(i)) pass++;
    else {bus++; pass=1; time=t.at(i)+k;}

    if(pass==c&&i<n-1){bus++; pass=0; time=t.at(i+1)+k;}
    if(i==n-1) bus++;
  }

  cout << bus;
}