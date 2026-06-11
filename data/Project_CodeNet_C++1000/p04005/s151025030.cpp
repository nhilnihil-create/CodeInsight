#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c;cin>>a>>b>>c;
  if(a%2==0 || b%2==0 || c%2==0)cout<<0;
  else{
  	long long maxi = 0;
    maxi = a*b;
    maxi = min(maxi,b*c);
    maxi = min(maxi,c*a);
    cout<<maxi;
  }
}