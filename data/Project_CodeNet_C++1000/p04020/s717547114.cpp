#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  ll vec[n];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  ll ans=0,i=0,z=0;
  while(i<n){
    if(vec[i]==0){
      ans+=z/2;
      z=0;
      i++;
    }
    else{
      z+=vec[i];
      i++;
    }
  }
  cout<<ans+z/2<<endl;
}