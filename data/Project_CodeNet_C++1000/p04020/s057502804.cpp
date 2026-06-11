#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n;
  cin >> n;
  vector<ll>a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  ll count=0;
  for(int i=0; i<n; i++){
    ll add=a[i]/2;
    if(a[i]%2 && i<n-1){
      if(a[i+1]>0){
        a[i+1]--;
        add++;
      }
    }
    count+=add;
  }
  
  
  cout << count << endl;
  
}
  
  
  
