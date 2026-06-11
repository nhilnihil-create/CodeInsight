#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,k;
  cin>>n>>k;
  ll vec[110000]={};
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    vec[a]+=b;
  }
  ll sum=0;
  for(int i=0;i<110000;i++){
    sum+=vec[i];
    if(sum>=k){
      cout<<i<<endl;
      return 0;
    }
  }
}