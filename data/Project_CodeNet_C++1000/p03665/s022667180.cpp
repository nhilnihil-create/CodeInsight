#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,p;
  cin >> n >> p;

  int e=0, o=0;
  rep(i,n){
    int a;
    cin >> a;
    if(a%2==0) e++;
    else o++;
  }

  ll ans=0;
  ll e_a=0, o_a=0;
  e_a = pow(2,e);

  ll k=o*p + abs(p-1);
  o_a += k;
  for(int i=p+2; i<=n; i+=2){
    k = k*(o+2-i)*(o-i+1);
    k = k/((i)*(i-1));
    o_a += k;
    //cout << k << endl;
  }

  ans = e_a * o_a;
  cout << ans;
}