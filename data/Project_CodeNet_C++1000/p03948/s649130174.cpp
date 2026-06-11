#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)



int main(){
  int n,t;
  cin >> n >> t;
  ll a[n];
  rep(i,n) cin >> a[i];

  ll tmin=a[0];
  ll tpro=0;
  ll c=0;
  ll fac=1LL;
  rep1(i,n-1){
    if(a[i]-tmin>tpro){
      c=1LL*fac;
      tpro=a[i]-tmin;
    }
    else if(a[i]-tmin==tpro){
      c+=fac;
    }
    else if(tmin > a[i]){
      tmin=a[i];
      fac=1LL;
    }
    else if(tmin == a[i]){
      fac++;
    }
  }
  cout << c << endl;
  return 0;

}
