#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll n;
  cin >> n;
  vector<vector<ll>>a(n,vector<ll>(2));
  for(int i=0; i<n; i++){
    cin >> a[i][0];
    a[i][1]=i+1;
  }
  
  sort(a.begin(),a.end());
  for(int i=0; i<n; i++){
    a[i][0]=i+1;
  }
  
  ll count=0;
  for(int i=0; i<n; i++){
    ll x=a[i][0]%2,y=a[i][1]%2;
    if(x!=y)count++;
  }
  
  cout << count/2 << endl;
  
  
}
  
  
  
  
