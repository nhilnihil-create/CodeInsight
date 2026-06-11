#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) {
    cin>>a[i];
    a[i]--;
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(a[a[i]]==i) ans++;
  }
  cout<<ans/2<<endl;
  return 0;
}
