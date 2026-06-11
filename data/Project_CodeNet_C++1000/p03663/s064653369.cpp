#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){ 
  ll k=1;
  char c;
  int f=0;
  for(ll i=0;i<11;i++){
    cout<<"? "<<k<<endl;
    cin>>c;
    if(c=='N'){
	 f=1;
	 break;
    }
    k*=10;
  }
  if(f==0){
    ll a=1;
    ll b=9;
    for(int i=0;i<11;i++){
	 cout<<"? "<<b<<endl;
	 cin>>c;
	 if(c=='Y'){
	   cout<<"! "<<a<<endl;
	   return 0;
	 }
	 a*=10;
	 b*=10;
    }
  }
  ll ok=k-1,ng=k/10-1,mid;
  while(ok-ng>1){
    mid=(ng+ok)/2;
    cout<<"? "<<mid<<"000"<<endl;
    cin>>c;
    if(c=='Y')ok=mid;
    else ng=mid;
  }
  cout<<"! "<<ok<<endl;
  return 0;
}
