#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fun(ll n, ll s){

  ll a[n],sum=0;
  for(ll i=0;i<n;i++){cin>>a[i];sum+=a[i];}
  ll l,r;
  l=0,r=n-1;
   while(l<r){
    if(a[l]<a[r]&&sum-a[l]>=s){
       sum-=a[l++];

    }else if(sum-a[r]>=s){
       sum-=a[r--];
    }else break;

   }
  cout << r-l+1 ;
 cout << "\n" ;
}

int main(){
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
  ll n,s;
  cin>>n;
  ll a[n],sum=0;
  for(ll i=0;i<n;i++){
    cin >>a[i];
  }
  ll r=0;
  for(ll i=0;i<n;i++){
    ll j=i;
    ll sum=0;
    while(j<n && a[j])
        sum+=a[j++];
    r+=sum/2;
   i=j;

  }
  cout << r;
}
