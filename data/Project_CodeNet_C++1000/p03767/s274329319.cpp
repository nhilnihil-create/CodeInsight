#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000001
//0=48,A=65,a=97
 
int main(){
  int n;cin >> n;
  vector<int> a(3*n);for(int i=0;i<3*n;i++) cin >> a[i];
  sort(a.begin(),a.end());
  ll ans=0;
  for(int i=n;i<3*n;i+=2) ans+=a[i];
  
  cout << ans;
}