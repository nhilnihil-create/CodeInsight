#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  ll ans =0;
  ll n,a,b; cin >> n >> a >> b;
  ll aa = a*(n-1) + b;
  ll bb = b*(n-1) + a;

  if(n==1&&a!=b){
    ans =0;
  }else{
    ans = bb-aa;
    if(ans<0) ans =0;
    else ans++;
  }

  cout << ans <<endl;

}