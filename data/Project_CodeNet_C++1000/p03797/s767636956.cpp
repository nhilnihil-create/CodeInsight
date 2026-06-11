#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n >> m;
  if(2*n>=m){
    cout << m/2;
  }else{
    ll ans=0;
    ans+=n;
    m-=2*n;
    ans+=m/4;
    cout << ans;
  }
}