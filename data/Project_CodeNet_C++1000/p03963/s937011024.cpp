#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int  n,k; cin>>n>>k;
  ll ans=k*pow(k-1,n-1);
  cout<<ans<<endl;
}
      