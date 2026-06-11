#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll p[n];
  rep(i,n){
    cin >> p[i];
    p[i]--;
  }
  ll a[n], b[n];
  rep(i,n){
    a[i]=(i+1)*1LL*3e4;
    b[n-1-i]=(i+1)*1LL*3e4;
  }
  rep(i,n){
    b[p[i]]+=i;
  }
  rep(i,n) cout << a[i] << " ";
  cout << "" << endl;
  rep(i,n) cout << b[i] << " ";
  cout << "" << endl;
  //  rep(i,n) cout << a[p[i]]+b[p[i]] << " ";
  
  return 0;
    

}
