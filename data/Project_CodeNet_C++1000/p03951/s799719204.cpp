#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n;
  string s,t;
  cin>>n>>s>>t;
  int ans=2*n;
  for(int i=1;i<=n;i++){
    if(s.substr(s.size()-i,i)==t.substr(0,i)) ans=2*n-i;
  }
  cout<<ans<<endl;
  return 0;
}
