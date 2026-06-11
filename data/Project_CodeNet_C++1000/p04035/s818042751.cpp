#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n,l;
  cin >> n >> l;
  vector<ll>a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  
  int start=0;
  for(int i=0; i<n-1; i++) {
    if(a[i]+a[i+1]>=l){
      start=i+1;
      break;
    }
  }
  
  if(start==0){
    cout << "Impossible" << endl;
    return 0;
  }
  
  cout << "Possible" << endl;
  for(int i=1; i<start; i++) cout << i << endl;
  for(int i=n-1; i>start; i--) cout << i << endl;
  cout << start << endl;
  
}
  
  
  
  
