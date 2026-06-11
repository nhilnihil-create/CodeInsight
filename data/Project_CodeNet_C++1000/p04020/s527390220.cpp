#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;++i){
    cin >> a[i];
  }
  ll res=0;
  ll su=0;
  int i=0;
  while(i<n){
    int j=i;
    while(j<n && a[j]>0){
      su+=a[j];
      j++;
    }
    res+=su/2;
    su=0;
    i=j+1;
  }
  cout << res << endl;
  return 0;
}
