#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main(){
  ll n;
  cin>>n;
  ll t,a;
  ll tv,av;
  cin>>tv>>av;
  
  for(int i=1;i<n;i++){
    cin>>t>>a;
       
   	ll aa=(tv+t-1)/t;
    ll bb=(av+a-1)/a;
    ll mx=bb;
    if(aa>bb){
      mx=aa;
    }

    tv=mx*t;
    av=mx*a;
  }
  
  cout<<(tv+av)<<endl;
  return 0;
}