#include <bits/stdc++.h>
using namespace std;
//型に気を付けよう

#define rep(i,n) for(int i=0;i<n;i++)
typedef long long  ll;
typedef long double  ld;
typedef pair<int,int> pairii;
const double pi=3.1415926535;
const ll  mod=1000000007;
//桁数指定　cout << fixed << setprecision(2)
int main() {
  int n;
  cin>>n;
  vector<ll> a(3*n);
  rep(i,3*n){
   cin>>a[i];cerr<<a[i];
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll ans=0;
  rep(j,n){
    ans+=a[j*2+1];
  }
  cout<<ans<<endl;
}
