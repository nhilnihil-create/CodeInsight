#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  ll cnt=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]%2==1)cnt++;
  }
  if(cnt%2==0)cout<<"YES";
  else cout<<"NO";
}