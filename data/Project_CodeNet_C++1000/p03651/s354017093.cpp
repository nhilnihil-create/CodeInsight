#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main(){
  
  ll n,k;
  cin>>n>>k;
  ll a[n];
  ll maxa=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    maxa=max(a[i],maxa);
  }
  ll gcd=a[0];
  for(int i=1;i<n;i++){
    gcd=GCD(gcd,a[i]);
  }
  if(k%gcd==0&&maxa>=k) cout<<"POSSIBLE"<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
  
}