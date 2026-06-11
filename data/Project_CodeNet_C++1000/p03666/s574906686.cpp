#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  ll a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  for(int i=0;i<n;i++){
    int j=n-i-1;
    ll maxb=a+i*d-j*c;
    ll minb=a+i*c-j*d;
    if(minb<=b&&b<=maxb){
      cout<<"YES"<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
}