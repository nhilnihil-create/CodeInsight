#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++)cin >> a[i];
  sort(a.begin(),a.end());
  vector<ll> c(n);
  ll k=0;
  for(ll i=0;i<n;i++){
    if(a[i]==a[i+1]){
      c[k++]=a[i];
      i++;
    }
  }
  cout << c[k-2]*c[k-1] << endl;
}
