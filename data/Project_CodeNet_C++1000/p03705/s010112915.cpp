#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;


int main(){
  ll n,b,a;
  cin >> n >> a >> b;

  b=b-a+1;
  a=1;

  ll ans,minsum,maxsum;

  minsum=a*(n-1)+b;
  maxsum=a+b*(n-1);

  ans=maxsum-minsum;

  if(a>b){
    cout << 0 << endl;
    return 0;
  }
  if(n==1 && a!=b){
    cout << 0 << endl;
    return 0;
  }
  cout << ans+1 << endl ;


  }
