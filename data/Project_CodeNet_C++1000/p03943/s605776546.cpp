#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const ll INF=1e18;
const int MOD=1e9+7;
const double pi=acos(-1);

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  if(a+b==c || b+c==a || c+a==b)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
